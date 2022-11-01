/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:34:54 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/10/04 15:34:56 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

namespace ft
{
	template <class Iter>
	class iterator_traits
	{
		typedef typename Iter::difference_type		dt;
		typedef typename Iter::value_type		vt;
		typedef typename Iter::pointer			ptr;
		typedef typename Iter::reference		rhs;
		typedef typename Iter::iterator_category	ic;
	};
	
	//If Iter does not have pointer, but has all four remaining member types, then the member types are declared as follows: 
	template <class Iter>
	class iterator_traits
	{
		typedef typename Iter::difference_type		dt;
		typedef typename Iter::value_type		vt;
		typedef typename void				ptr;
		typedef typename Iter::reference		rhs;
		typedef typename Iter::iterator_category	ic;
	};

	template< class T >
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t	dt;
		typedef T 		vt;
		typedef T*	ptr;
		typedef T&	rhs;
		typedef std::random_access_iterator_tag ic;
	};
	
	template< class T >
	struct iterator_traits<const T*>
	{		
		typedef std::ptrdiff_t	dt;
		typedef T 		vt;
		typedef const T*	ptr;
		typedef const T&	rhs;
		typedef const std::random_access_iterator_tag ic;
	};
}

#endif
