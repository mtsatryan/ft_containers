/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:30:41 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/26 15:30:43 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "ft_containers.hpp"

namespace ft
{

    template <class T, class Container>
    class stack 
    {
        public:
            typedef typename Container::value_type  value_type;
            typedef typename Container::size_type   size_type;
            typedef          Container              container_type;
        protected:
            container_type c;
        public:
            explicit stack(const container_type& container = container_type()): c(container) {};

            bool                empty() const               { return c.empty(); }
            size_type           size()  const               { return c.size(); }
            value_type&         top()                       { return c.back(); }
            const value_type&   top() const                 { return c.back(); }
            void                push(const value_type& x)   { c.push_back(x); }
            void                pop()                       { c.pop_back(); }
    
            template <class Y, class Cont> friend bool operator==(const stack<Y, Cont>& x, const stack<Y, Cont>& y) { return ( x.c == y.c); }
            template <class Y, class Cont> friend bool operator< (const stack<Y, Cont>& x, const stack<Y, Cont>& y) { return ( x.c <  y.c); }
            template <class Y, class Cont> friend bool operator!=(const stack<Y, Cont>& x, const stack<Y, Cont>& y) { return ( x.c != y.c); }
            template <class Y, class Cont> friend bool operator> (const stack<Y, Cont>& x, const stack<Y, Cont>& y) { return ( x.c > y.c); }
            template <class Y, class Cont> friend bool operator>=(const stack<Y, Cont>& x, const stack<Y, Cont>& y) { return ( x.c >= y.c); }
            template <class Y, class Cont> friend bool operator<=(const stack<Y, Cont>& x, const stack<Y, Cont>& y) { return ( x.c <= y.c); }
    };
}

#endif
