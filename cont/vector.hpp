/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <mtsatrya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:10:25 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/11/05 16:08:37 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory> // for ALLOCATOR
#include "ft_containers.hpp"

namespace ft
{

	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T 												value_type;						
		typedef Alloc											allocator_type;					
		typedef	allocator_type::size_type						size_type;						
		typedef allocator_type::difference_type					difference_type;				
		typedef typename allocator_type::reference				referennce;						
		typedef typename allocator_type::const_reference		const_reference;				
		typedef typename allocator_type::pointer				pointer;						
		typedef typename allocator_type::const_pointer			const_pointer;					
		typedef ft::random_access_iterator<value_type>			iterator;						
		typedef ft::random_access_iterator<const value_type>	const_iterator;					
		typedef ft::reverse_iterator<iterator>					reverse_iterator;				
		typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;			


	private:
		pointer			_ptr;																	
		allocator_type	_alloc;																	
		size_type		_capacity;																
		size_type		_size;																	
	
	public:
		// CONSTRUCTORS //
		explicit vector (const allocator_type& alloc = allocator_type()) : _ptr(NULL), _alloc(NULL), _capacity(NULL), _size(NULL) {}
		
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) : _capacity(n), _alloc(alloc) 
		{
			_size = 0;
			_ptr = alloc->allocate(n);
			while (_size < n)
			{
				_ptr + _size = val;
				_size++;
			}
		}
		
		template<class InputIterator>
		vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{
			while (first <= last)
			{
				_ptr = alloc->allocate(this);
				first++;
			}
		}
		
		vector( const vector& other ) : _size(NULL), _capacity(NULL) { *this = other; }

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
			size_type i;

			i = 0;
			if (this == &x)
				return (*this);
			while (i < _size)
			{
				_alloc.destroy(_ptr + i);
				i++;
			}
			this->_size = x._size;
			if (_capacity < _size)
			{
				if (_capacity != 0)
					_capacity(_ptr, _capacity);
				_capacity = _size;
				_ptr = _alloc.allocate(_capacity);
			}
			i = 0;
			while (i < _size)
			{
				_alloc.construct(_ptr + i, x[i]);
				i++;
			}
			return (*this);
		}
		
		// ASSIGN //
		void assign(size_type count, const T& value)
		{
			size_type i;

			i = 0;
			while(i < _size)
			{
				_alloc.destroy(_ptr + i);
				i++;
			}
			_size = 0;
			if (count > _capacity)
			{
				_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(count);
				_capacity = count;
			}
			i = 0;
			while(i < count)
			{
				_alloc.construct(_ptr + i, value);
				i++;
			}
			_size = count;
		}


		template< class InputIterator >
		void assign( InputIterator first, InputIterator last ) //enable_if<!is_integral<InputIterator>::value>::type* = 0 ==> WTF IS THAT
		{
			size_type i;

			i = 0;	
			if (first < last)
				throw std::logic_error("vector");
			difference_type count = last - first;
			while(i < _size)
			{
				_alloc.destroy(_ptr + i);
				i++;
			}
			_size = 0;
			if (count < static_cast<difference_type>(_capacity()))
			{
				_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(count);
				_capacity = count;
			}
			iterator tmp = begin();
			while (first < last)
			{
				_alloc.construct(tmp.base(), *first);
				tmp++;
				first++;
			}
			_size = count;
		}

		// ALLOCATOR GETTER //
		allocator_type get_allocator() const { return (_alloc); }

		// ITERATOTS //
		 iterator begin()
		 {
			iterator tmp;
			tmp = _ptr;
			return (tmp);
			// CAN I WRITE LIKE THAT: return (iterator tmp = _ptr);
		 }

		 const_iterator begin() const
		 {
			const_iterator tmp;
			tmp = _ptr;
			return (tmp);
			// CAN I WRITE LIKE THAT: return (iterator const_tmp = tmp);
		 }

		 iterator end()
		 {
			iterator tmp;
			tmp = _ptr + _size;
			return (tmp);
			// CAN I WRITE LIKE THAT: return (iterator tmp = _ptr + size);
		 }
		 const_iterator end() const
		 {
			const_iterator tmp;
			tmp = _ptr + size;
			// CAN I WRITE LIKE THAT: return (iterator const_tmp = _ptr + size);
		 }

		 reverse_iterator rbegin()
		 {
			reverse_iterator tmp;
			tmp = _ptr + size;
			return (tmp);
		 }
		 
		 const_reverse_iterator rbegin() const
		 {
			const_reverse_iterator tmp;
			tmp = _ptr + size;
			return (tmp);
		 }

		 reverse_iterator rend()
		 {
			reverse_iterator tmp;
			tmp = _ptr;
			return (tmp);
		 }
		 
		 const_reverse_iterator rend() const
		 {
			const_reverse_iterator tmp;
			tmp = _ptr;
			return (tmp);
		 }

		 // CAPACITY

		size_type size() const { return (this->_size); }
		size_type max_size() const { return (_alloc.max_size()); }
		size_type capacity() const { return (this->_capacity); }
		bool empty() const { return (!this->_size); } 					// || _size == 0

		void resize (size_type n, value_type val = value_type())
		{
			iterator res;

			res = this->end();
			if (n > this->max_size())
				throw(std::length_error("vector::resize"));
			else if (n < this->size())
			{
				while (this->size() > n)
				{
					--res;
					_alloc(destroy(res));
				}
			}
			else 
				this->insert(this->end(), n - this->size(), val);
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
				while (tmp + i = NULL && i < _size)
				{
					_alloc.destroy(tmp + i);
					i++;
				}
				_alloc.deallocate(tmp, n);
				throw;
			}
			for (size_type _i = 0; _i < _size; _i++)
				_alloc.destroy(_ptr + i);
			if (_capacity)
				_alloc.deallocate(_ptr, _capacity);
			_capacity = n;
			_ptr = tmp;
		}

		/* MODIFIERS
		!	assign
		!	push_back
		!	pop_back
			insert
			erase
			swap
			clear
			emplace
			emplace_back
		*/

		void push_back (const value_type& val)
		{
			if (_size == _capacity)
			{
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_capacity * 2);
			}
			_alloc.construct(_ptr + _size, val);
			_size++;
		}

		void pop_back()
		{
			_alloc.destroy(_ptr + _size - 1);
			_size--;
		}


		iterator insert (iterator position, const value_type& val)
		{ 
			if (position < begin() || position > end())
				throw std::logic_error("vector");
			difference_type tmp = position - begin();
			if (_size == _capacity)
			{

			}
		}
		
		void insert (iterator position, size_type n, const value_type& val)
		{
			const size_type i = position - this->begin();

		}
		
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{

		}


		/* ELEMENT ACCESS
			operator[]
			at
			front
			back
			data		
		*/  
	
	};
}

#endif
