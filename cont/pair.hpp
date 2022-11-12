/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <mtsatrya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:36:20 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/11/03 20:45:56 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<class T1, class T2> struct pair;
	// MEMBER TYPES
	typedef T1 first_type;
	typedef T2 second_type;
	// MEMBER OBJECTS
	first_type first;
	second_type second;

// MEMBER FUNCTIONS
	// CONSTRUCTORS
			pair() : first(), second() { }
			template<class U, class V>pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) { }
			pair (const first_type &a, const second_type &b) : first(a), second(b) { } 
	// OPERATOR=
			pair &operator=(const pair &pr)
			{
				first = pr.first;
				second = pr.second;

				return (*this);
			}
	// SWAP
			template <class T1, class T2>
			void    swap(T& a, T& b)
			{
			   	T tmp;

				tmp = a;
				a = b;
			    b = tmp;
			}
// NON-MEMBER FUNCTIONS
			// MAKE_PAIR
			template <class T1, class T2>
			pair<T1, T2> make_pair(T1 x, T2 y)
			{
				return (pair<T1, T2>(x, y) );
			}
			// OPERATORS
			// ==
			template<class T1, class T2>
			bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
			{
				if (lhs.first == rhs.first && lhs.second == rhs.second)
					return (true);
				else
					return (false);
			}
			// !=
			template<class T1, class T2>
			bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
			{
				if (lhs.first != rhs.first && lhs.second != rhs.second)
					return (true);
				else
					return (false);
			}
			// <
			template<class T1, class T2>
			bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
			{
				if (lhs.first < rhs.first)
				{
					if (lhs.second < rhs.second)
						return (true);
					else
						return (false);
				}
				else
					return (false);
			}
			// <=
			template<class T1, class T2>
			bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
			{
				if (lhs.first <= rhs.first)
				{
					if (lhs.second <= rhs.second)
						return (true);
					else
						return (false);
				}
				else
					return (false);
			}
			// >
			template<class T1, class T2>
			bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
			{
				if (lhs.first > rhs.first)
				{
					if (lhs.second > rhs.second)
						return (true);
					else
						return (false);
				}
				else
					return (false);
			}
			// >=
			template<class T1, class T2>
			bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
			{
				if (lhs.first >= rhs.first)
				{
					if (lhs.second >= rhs.second)
						return (true);
					else
						return (false);
				}
				else
					return (false);
			}
}

#endif
