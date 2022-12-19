/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:37:46 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/16 20:14:47 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

namespace ft
{
    template<class T, class Allocator = std::allocator<T> >
    class vector;

    template <class T, class Container = ft::vector<T> >
    class stack;
}

#include <memory>
#include <cstddef>
#include <iostream>

#include "enable_if.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "iterators_traits.hpp"
#include "iterator.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "RandomAccessIterator.hpp"
#include "rbtree.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "map.hpp"

#endif
