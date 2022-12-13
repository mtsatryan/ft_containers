/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:35:51 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/09 16:15:33 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

#include "ft_containers.hpp"

namespace ft
{
	template <class InputIterator1, class InputIterator2>
		bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
		{
			while (first1!=last1)
			{
				if (!(*first1 == *first2))
					return false;
				++first1; ++first2;
			}
			return true;
		}
}

#endif
