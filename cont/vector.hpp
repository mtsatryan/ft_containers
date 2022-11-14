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
		typedef T 												value_type;						// !
		typedef Alloc											allocator_type;					// !
		typedef	allocator_type::size_type						size_type;						// !
		typedef allocator_type::difference_type					difference_type;				// !
		typedef typename allocator_type::reference				referennce;						// !
		typedef typename allocator_type::const_reference		const_reference;				// !
		typedef typename allocator_type::pointer				pointer;						// !
		typedef typename allocator_type::const_pointer			const_pointer;					// !
		typedef ft::random_access_iterator<value_type>			iterator;						// !
		typedef ft::random_access_iterator<const value_type>	const_iterator;					// !
		typedef ft::reverse_iterator<iterator>					reverse_iterator;				// !
		typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;			// !


	private:
		pointer			_ptr;																	// ! this is where the fun begins
		allocator_type	_alloc;																	// ! 
		size_type		_capacity;																// !
		size_type		_size;																	// !
	
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
		vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) // DELETE CHAR C AFTER YOU ADD ENABLE_IF
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
		void assign( InputIterator first, InputIterator last )
		{
			
		}
		// ALLOCATOR GETTER //
		allocator_type get_allocator() const;
	};
}

#endif
