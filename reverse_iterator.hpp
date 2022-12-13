/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:35:06 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/09 15:36:31 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "ft_containers.hpp"

namespace ft
{
	template <class Iterator>
    class reverse_iterator
	{
	protected:
		Iterator current;
	public:
		typedef Iterator                                                iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
		typedef typename iterator_traits<Iterator>::value_type          value_type;
		typedef typename iterator_traits<Iterator>::difference_type     difference_type;
		typedef typename iterator_traits<Iterator>::pointer             pointer;
		typedef typename iterator_traits<Iterator>::reference           reference;

	
	reverse_iterator() {}
	reverse_iterator(Iterator x) : current(x) { }
	
	template <class U>
	reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) { }

	template <class U>
	reverse_iterator &operator=(const reverse_iterator<U> &r)
	{
		current = r.base();
		return *this;
	}
	
	iterator_type base() const { return current; }; 
	
  	reverse_iterator& operator++()
	{
		--current;
		return *this;
	}
	
	reference	operator*() const
	{
		Iterator tmp = current;
		return *--tmp;
	}
	
	pointer operator->() const { return &(operator*()); }
  	
	reverse_iterator  operator++(int)
	{
		reverse_iterator tmp = *this;
		--current;
		return tmp;
	}
	
  	reverse_iterator& operator--()
	{
		++current;
		return *this;
	}
  	
	reverse_iterator  operator--(int)
	{
		reverse_iterator tmp = *this;
		++current;
		return tmp;
	}
  	
	reverse_iterator  operator+(difference_type n) const
	{
		reverse_iterator tmp(*this);
		tmp += n;
		return tmp;
		// return reverse_iterator(current - n);
	}
	
  	reverse_iterator& operator+=(difference_type n)
	{
		current -= n;
		return *this;
	}
  	
	reverse_iterator  operator- (difference_type n) const
	{
		reverse_iterator tmp(*this);
		tmp -= n;
		return tmp;
	}
  	
	reverse_iterator& operator-=(difference_type n)
	{
		current += n;
		return *this;
	}

	

	// difference_type operator-(const reverse_iterator &rhs)
	// {
	// 	difference_type diff = 0;
	// 	diff = current - rhs.current;
	// 		return diff;
	// }
	
	reference operator[](difference_type n) const { return *(base() - n - 1); }

    // operator reverse_iterator<const iterator_type> ()
    // {
    //     return (reverse_iterator<const iterator_type>(current));
    // }
	
	//~reverse_iterator() { }
};
	// template <class Iterator>
	
	
	
	template <class Iterator>
	bool operator!=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y)
		{
			return !(x.base() == y.base());
		}
		template <class Iterator>
	bool operator==(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y)
		{
			return (x.base() == y.base());
		}
	template <class Iterator>
	bool operator<(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y)
		{
			return x.base() > y.base();
		}
	template <class Iterator>
	bool operator>(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y)
		{
			    return x.base() < y.base();
		}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return !(x.base() > y.base());
	}
	
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return !(x.base() < y.base());
	}
    
	
	
	template <class Iterator, class Iterator2>
	bool operator!=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator2>& y)
		{
			return !(x.base() == y.base());
		}
		template <class Iterator, class Iterator2>
	bool operator==(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator2>& y)
		{
			return (x.base() == y.base());
		}
	template <class Iterator, class Iterator2>
	bool operator<(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator2>& y)
		{
			return y.base() < x.base();
		}
	template <class Iterator, class Iterator2>
	bool operator>(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator2>& y)
		{
			    return y.base() > x.base();
		}

	template <class Iterator, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator2>& y)
	{
		return !(x.base() > y.base());
	}
	
	template <class Iterator, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator2>& y)
	{
		return !(x.base() < y.base());
	}
    
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y)
		{
			return y.base() - x.base();
		}
		template <class Iterator, class Iterator1>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator1>& y)
		{
			return y.base() - x.base();
		}
    
	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n, 
		const reverse_iterator<Iterator>& x)
		{
			return reverse_iterator<Iterator>(x + n);
		}
}

#endif
