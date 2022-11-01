/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <mtsatrya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:10:25 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/11/01 23:21:09 by mtsatrya         ###   ########.fr       */
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
		typedef T&										referennce;
		typedef	const T									const_reference;
		typedef Allocator::pointer						pointer;
		typedef Allocator::const_pointer				const_pointer;
		typedef ft::iterator<iterator>					iterator;
		typedef ft::reverse_iterator<iterator>			const_iterator;
		typedef	ft::reverse_iterator<const_iterator>	reverse_iterator;

		// CONSTRUCTORS //
		vector();
		explicit vector( const Allocator& alloc );
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
		vector( const vector& other );

		// DESTRUCTOR //
		~vector();

		// OPERATOR //
		vector& operator=( const vector& other );
		
		// ASSIGN //
		void assign( size_type count, const T& value );
		template< class InputIt >
			void assign( InputIt first, InputIt last );
		// ALLOCATOR //
		allocator_type get_allocator() const;
	};
}

#endif
