/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:29:22 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/26 15:29:23 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

#include <memory>
#include <cstddef>
#include <iostream>

namespace ft
{
    template<class T, class Allocator = std::allocator<T> >
    class vector;

    template <class T, class Container = ft::vector<T> >
    class stack;
}

#include "utility.hpp"
#include "iterators_traits.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "RandomAccessIterator.hpp"
#include "rbtree.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "map.hpp"

#endif
