/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:29:29 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/26 15:29:31 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "ft_containers.hpp"

namespace ft
{
    template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator 
    {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
        struct input_iterator_tag {};
        struct output_iterator_tag {};
        struct forward_iterator_tag: public input_iterator_tag {};
        struct bidirectional_iterator_tag: public forward_iterator_tag {};
        struct random_access_iterator_tag: public bidirectional_iterator_tag {};

}

#endif
