/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:34:54 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/05 19:50:54 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include "ft_containers.hpp"

namespace ft
{
	template <class Iter>
	struct iterator_traits
	{
		public:
			typedef typename Iter::difference_type			difference_type;
			typedef typename Iter::value_type				value_type;
			typedef typename Iter::pointer					pointer;
			typedef typename Iter::reference				reference;
			typedef typename Iter::iterator_category		iterator_category;
	};

	template< class T >
	struct iterator_traits<T*>
	{
		public:
			typedef std::ptrdiff_t							difference_type;
			typedef T 										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef std::random_access_iterator_tag 		iterator_category;
	};
	
	template< class T >
	struct iterator_traits<const T*>
	{	
		public:	
			typedef std::ptrdiff_t							difference_type;
			typedef T 										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef const std::random_access_iterator_tag 	iterator_category;
	};
	
	template <class Iterator>
    typename iterator_traits<Iterator>::difference_type    distance (Iterator first, Iterator last)
    {
        typename ft::iterator_traits<Iterator>::difference_type diff = 0;
        
        while (first != last)
        {
            ++first;
            ++diff;
        }
        return diff;
	}
}

#endif
