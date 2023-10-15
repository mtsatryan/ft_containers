/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:30:49 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/26 15:30:50 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "ft_containers.hpp"

namespace ft
{
    // IS_INTEGRAL
    template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator T() { return v; }
	};
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;
	
	template <class T> struct is_integral					: false_type	{};
	template <> struct is_integral<bool> 					: true_type		{};
	template <> struct is_integral<char> 					: true_type		{};
	template <> struct is_integral<wchar_t> 				: true_type 	{};
	template <> struct is_integral<signed char> 			: true_type 	{};
	template <> struct is_integral<short int> 				: true_type 	{};
	template <> struct is_integral<int> 					: true_type 	{};
	template <> struct is_integral<long int> 				: true_type 	{};
	template <> struct is_integral<long long int> 			: true_type 	{};
	template <> struct is_integral<unsigned char> 			: true_type 	{};
	template <> struct is_integral<unsigned short int>		: true_type 	{};
	template <> struct is_integral<unsigned int> 			: true_type 	{};
	template <> struct is_integral<unsigned long int> 		: true_type 	{};
	template <> struct is_integral<unsigned long long int>	: true_type 	{};


    // ENABLE_IF
    template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> { typedef T type; };


	// PAIR
    template<class T1, class T2>
	struct pair
	{
	
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;
		
		pair() : first(), second() { }
		//pair(void) : first(first_type ()), second(second_type ()) {}

		template<class U1, class U2>
		pair(const pair<U1, U2> &cpy) : first(cpy.first), second(cpy.second) {}

		pair (const first_type& f, const second_type& s) : first(f), second(s) { }
		// pair(const first_type &f, const second_type &s) //:  first(f), second(s)
        // {
		// 	first  = f;
		// 	second = s;
        // }

		pair	&operator=(const pair &cpy)
		{
			first = cpy.first;
			second = cpy.second;
			return (*this);
		}

	};

	template<class T1, class T2>
	ft::pair<T1, T2>	make_pair(const T1 f, const T2 s)
	{ return (ft::pair<T1, T2> (f, s)); }

	template<class T1, class T2>
	bool	operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{ return (lhs.first  == rhs.first && lhs.second == rhs.second); }

	template<class T1, class T2>
	bool	operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{ return (!(lhs == rhs)); }
	
	template<class T1, class T2>
	bool	operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{ return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second)); }

	template<class T1, class T2>
	bool	operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{ return (lhs == rhs || lhs < rhs); }

	template<class T1, class T2>
	bool	operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{ return (!(lhs <= rhs)); }

	template<class T1, class T2>
	bool	operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
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
    
    // LEXICOGRAPHICAL_COMPARE
	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2<*first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

    // EQUAL
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
