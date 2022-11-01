/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:35:41 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/10/04 22:34:01 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <class T, T V>
		struct is_integral
		{
			//generic
			template <typename T>
    			struct is_integral { static const bool value = false; };
			//bool
			template <>
    			struct is_integral<bool> { static const bool value = true; };
			//char
     			template <>
			struct is_integral<char> { static const bool value = true; };
			//char16_t
			template <>
			struct is_integral<char16_t> { static const bool value = true; };
			//char32_t
			template <>
			struct is_integral<char32_t> { static const bool value = true; };
			//wchar_t
			template <>
			struct is_integral<wchar_t> { static const bool value = true; };
			//short
			template <>
			struct is_integral<short> { static const bool value = true; };
			//int
			template <>
			struct is_integral<int> { static const bool value = true; };
			//long
			template <>
			struct is_integral<long> { static const bool value = true; };
			//long long
			template <>
			struct is_integral<long long> { static const bool value = true; };
		}
}

#endif
