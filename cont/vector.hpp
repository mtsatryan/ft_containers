/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <mtsatrya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:10:25 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/11/04 18:47:12 by mtsatrya         ###   ########.fr       */
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
		typedef T 										value_type;
		typedef Alloc									allocator_type;
		typedef	size_t									size_type;
		typedef ptrdiff_t								difference_type;
		typedef allocator_type::reference				referennce;
		typedef	allocator_type::const_reference			const_reference;
		typedef allocator_type::pointer					pointer;
		typedef allocator_type::const_pointer			const_pointer;
		typedef ft::iterator<iterator>					iterator;
		typedef ft::reverse_iterator<iterator>			const_iterator;
		typedef	ft::reverse_iterator<const_iterator>	reverse_iterator;


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
		
		template< class InputIt >
			vector( InputIt first, InputIt last, char c, const Allocator& alloc = Allocator()); // DELETE CHAR C AFTER YOU ADD ENABLE_IF
			
		vector( const vector& other );

		// DESTRUCTOR //
		~vector()
		{
			
		}
		// OPERATOR //
		vector& operator=( const vector& other )
		{
			vector
		}
		
		// ASSIGN //
		void assign( size_type count, const T& value );
		template< class InputIt >
			void assign( InputIt first, InputIt last );
		// ALLOCATOR //
		allocator_type get_allocator() const;
	};
}

#endif
