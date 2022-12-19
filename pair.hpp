/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:36:20 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/19 18:35:03 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include "ft_containers.hpp"

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
	
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(void)
		: first(first_type ()), second(second_type ()) {}

		pair(const first_type &f, const second_type &s)
		:  first(f), second(s) {}

		template<class U1, class U2>
		pair(const pair<U1, U2> &cpy)
		: first(cpy.first), second(cpy.second) {}

		pair	&operator=(const pair &cpy)
		{
			first = cpy.first;
			second = cpy.second;
			return (*this);
		}

	};

	template<class T1, class T2>
	ft::pair<T1, T2>	make_pair(const T1 &f, const T2 &s)
	{ return (pair<T1, T2> (f, s)); }

	template<class T1, class T2>
	bool	operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (lhs.first  == rhs.first && lhs.second == rhs.second); }

	template<class T1, class T2>
	bool	operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (!(lhs == rhs)); }
	
	template<class T1, class T2>
	bool	operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second)); }

	template<class T1, class T2>
	bool	operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (lhs == rhs || lhs < rhs); }

	template<class T1, class T2>
	bool	operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (!(lhs <= rhs)); }

	template<class T1, class T2>
	bool	operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (!(lhs < rhs)); }
	
	// SWAP
	template <class T>
	void    swap(T& a, T& b)
	{
		T tmp;

		tmp = a;
		a = b;
		b = tmp;
	}
}

#endif
