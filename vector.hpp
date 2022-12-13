/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:10:25 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/09 17:38:58 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "ft_containers.hpp"


namespace ft
{
	template<class T, class Allocator>
	class vector
	{
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::RandomAccessIterator<value_type>		iterator;
		typedef ft::RandomAccessIterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		pointer			_ptr;																	
		allocator_type	_alloc;																	
		size_type		_capacity;																
		size_type		_size;																	
	
	public:
		// CONSTRUCTORS //
		explicit vector(const allocator_type &alloc = allocator_type ()) : _alloc(alloc), _capacity(0), _size(0) { }
		
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())  
		{
			_ptr = _alloc.allocate(n);
			
			_alloc = alloc;
			_size = n;
			_capacity = n;
			size_type i = -1;
			while (++i < n)
				_alloc.construct(_ptr + i, val);
		}
		
		template<class InputIterator>
		vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) : _alloc(alloc)
		{
			difference_type tmp = ft::distance(first,last);
			if (tmp < 0)
				throw std::length_error("vector");
			_size = ft::distance(first,last);
			_capacity = _size;
			_ptr = _alloc.allocate(_capacity);
			for (difference_type i = 0; i < static_cast<difference_type>(_size); i++)
			{
				// _alloc.construct(_ptr + i, *(first + i));
				_ptr[i] = *first;
				++first;
			}
		}
		
		vector( const vector& other ) : _capacity(0) , _size(0) { *this = other; }
		
		// DESTRUCTOR //
		~vector()
		{
			size_type i;

			i = 0;
			while(i < _size)
			{
				_alloc.destroy(_ptr + i);
				i++;
			}
			if (_capacity)
				_alloc.deallocate(_ptr, _capacity);
		}

		// OPERATOR= //
		vector& operator= (const vector& x)
		{
			size_type i = -1;
			if (this == &x)
				return *this;
			while (++i < _size)
				_alloc.destroy(_ptr + i);
			this->_size = x._size;
			if (_capacity < _size)
			{
				if (_capacity != 0)
					_alloc.deallocate(_ptr, _capacity);
				_capacity = _size;
				_ptr = _alloc.allocate(_capacity);
			}
			i = -1;
			while (++i < _size)
				_alloc.construct(_ptr + i, x[i]);
			return(*this);
		}
		
		// ASSIGN //
		void assign(size_type count, const T& val)
		{
			clear();
			if (count > _capacity)
			{
				if (_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(count);
				_capacity = count;
			}
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_ptr + i, val);
			_size = count;
		}


		template< class InputIterator >
		void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			difference_type tmp = ft::distance(first,last);
			if (tmp < 0)
				throw std::logic_error("vector");
			difference_type n = ft::distance(first, last);
			clear();
			if (n > static_cast<difference_type >(capacity()))
			{
				if (_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(n);
				_capacity = n;
			}
			iterator i = begin();
			while (first != last)
			{
				_alloc.construct(&(*i), *first);
				i++;
				first++;
			}
			_size = n;
		}

		// ALLOCATOR GETTER //
		allocator_type get_alloc() const { return (_alloc); }

		// ITERATOTS //
		iterator begin()
		{
			return (iterator(this->_ptr));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->_ptr));
		}

		iterator end()
		{
			return (iterator(_ptr + size()));
		}
		const_iterator end() const
		{
			return (const_iterator(this->_ptr + this->_size));
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(this->end());
		}
		
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator (this->end()));
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator (begin());
		}

		 // CAPACITY
		size_type size() const { return (this->_size); }
		size_type max_size() const { return (_alloc.max_size()); }
		size_type capacity() const { return (this->_capacity); }
		bool empty() const { return (!this->_size); }

		void resize( size_type count, T value = T() )
		{
			if (count > size())
				insert(end(), count - size(), value);
			else if (count < size())
				erase(begin() + count, end());
			else
				;
		}

		void reserve (size_type n)
		{
			if (n < _capacity)
				return ;
			pointer tmp = _alloc.allocate(n);
			try {
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(tmp + i, *(_ptr + i));
			} catch (std::exception &e) {
				size_type i = 0;
				while (tmp + i != NULL && i < _size)
				{
					_alloc.destroy(tmp + i);
					i++;
				}
				_alloc.deallocate(tmp, n);
				throw;
			}
			for (size_type _i = 0; _i < _size; _i++)
				_alloc.destroy(_ptr + _i);
			if (_capacity)
				_alloc.deallocate(_ptr, _capacity);
			_capacity = n;
			_ptr = tmp;
		}

		void push_back (const value_type& val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			erase(end() - 1);
		}
		
		iterator insert(iterator position, const value_type& val)
		{
			size_type	ipos = position - this->begin();
			if (!(_capacity - _size))
				reserve(_capacity ? _capacity * 2 : 1);
			position = this->begin() + ipos;
			for (iterator end = this->end(); end != position; end--)
				*end = *(end - 1);
			_alloc.construct(position.operator->(), val);
			_size++;
			return (position);
		}

		void     insert(iterator position, size_type n, const value_type& val)
		{
			size_type	ipos = position - this->begin();
			if (_capacity < _size + n)
			{
				if (_capacity * 2 > _size + n)
					reserve(_capacity * 2);
				else
					reserve(_size + n);
			}
			position = this->begin() + ipos;
			for (iterator end = this->end(); end != position; end--)
				*(end + n - 1) = *(end - 1);
			_size += n;
			while (n--)
				_alloc.construct(position.operator->() + n, val);
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			size_type	ipos = position - this->begin();
			if (_capacity < _size + ft::distance(first, last))
			{
				if (_capacity * 2 > _size + ft::distance(first, last))
					reserve(_capacity * 2);
				else
					reserve(_size + ft::distance(first, last));
			}
			position = this->begin() + ipos;
			for (iterator end = this->end(); end != position; end--)
				*(end + ft::distance(first, last) - 1) = *(end - 1);
			_size += ft::distance(first, last);
			for (; first != last; first++, position++)
				_alloc.construct(position.operator->(), *first);
		}

		iterator erase(iterator pos)
		{
			if (!_size || pos >= this->end())
				return (this->end());
			_alloc.destroy(pos.operator->());
			for (iterator poscpy = pos + 1; poscpy != this->end(); poscpy++)
				*(poscpy - 1) = *poscpy;
			_size--;
			return(pos);
		}

		iterator erase( iterator first, iterator last )
		{
			if (!_size || first >= this->end() || first >= last)
				return (this->end());
			iterator _end = this->end();
			for (iterator _fst = first; _fst != last && _fst != _end; _size--, _fst++)
				_alloc.destroy(_fst.operator->());
			for (iterator _fst = first; last < _end; _fst++, last++)
				*_fst = *last;
			return (first);
		}

		void swap( vector& other )
		{
			ft::swap(_alloc, other._alloc);
			ft::swap(_ptr, other._ptr);
			ft::swap(_size, other._size);
			ft::swap(_capacity, other._capacity);
		}

		void clear()
		{
			size_type i = -1;
			while (++i < _size)
				_alloc.destroy(_ptr + i);
			_size = 0;
		}
  
		reference operator[] (size_type n) { return (this->_ptr[n]); }
		const_reference operator[] (size_type n) const { return (this->_ptr[n]); }
		reference front() { return (this->_ptr[0]); }
		const_reference front() const { return (this->_ptr[0]); }
		reference back() { return (this->_ptr[this->_size - 1]); }
		const_reference back() const { return (this->_ptr[this->_size - 1]); }
		reference at (size_type n)
		{
			if (n > _capacity)
				throw std::out_of_range("vector at out of range");
			return (*(_ptr + n));
		}
		const_reference at (size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("vector at out of range");
			return (this->_ptr[n]);
		}
	};

	// external operator overloads
	template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x,
					const vector<T,Allocator>& y)
					{
						return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
					}
	
	template <class T, class Allocator>
		bool operator< (const vector<T,Allocator>& x,
						const vector<T,Allocator>& y)
						{
							return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());	
						}
	
	template <class T, class Allocator>
		bool operator!=(const vector<T,Allocator>& x,
						const vector<T,Allocator>& y)
						{
							return !(x == y);
						}

	template <class T, class Allocator>
		bool operator> (const vector<T,Allocator>& x,
						const vector<T,Allocator>& y)
						{
							return y < x;
						}
	
	template <class T, class Allocator>
		bool operator>=(const vector<T,Allocator>& x,
						const vector<T,Allocator>& y)
						{
							return !(x < y);
						}
	
	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x,
					const vector<T,Allocator>& y)
					{
						return !(y < x);
					}
					
	template <class T, class Allocator>
             void swap(vector<T,Allocator>& x, vector<T,Allocator>& y) { x.swap(y); }
}

#endif