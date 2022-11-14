/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <mtsatrya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:35:06 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/11/01 23:23:46 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{
	template<class Iterator> 
	class reverse_iterator {
	pulic:
		typedef Iterator												iterator_type;		//
		typedef typename iterator_traits<Iterator>::iterator_category 	iterator_category;	// 
		typedef typename iterator_traits<Iterator>::value_type			value_type;			//
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;	//
		typedef typename iterator_traits<Iterator>::pointer				pointer;			//
		typedef typename iterator_traits<Iterator>std::reference		reference;			//
	protected: 
		Iterator Iter;
	public:
		reverse_iterator() : Iter() { }														
		
		explicit reverse_iterator(iterator_type i) : Iter(i) { }							
		
		template<typename It>
			reverse_iterator(const reverse_iterator<It>& rev) : Iter(rev.base()) { }
		
		iterator_type base() { return this->Iter; }
		
		reverse_iterator	&operator=(const reverse_iterator &rhs)
		{
			this->Iter = rhs.Iter;
			return (*this);
		}
		
		reference	operator*() const
		{
			Iterator ptr = Iter;
			return (*--ptr);
		}
		
		pointer operator->() const { return &(operator*()); }

		reference operator[] (difference_type n) const { return *(*this + n); }

		reverse_iterator& operator++() { return ++(*this); }
		reverse_iterator& operator--() { return --(*this); }

		reverse_iterator  operator++(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}
		
		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}		

		reverse_iterator operator+( difference_type n ) const { return reverse_iterator ((base() - n)); }
		reverse_iterator operator-( difference_type n ) const { return reverse_iterator ((base() + n)); }
		reverse_iterator& operator+=( difference_type n ) { base() -= n; }
		reverse_iterator& operator-=( difference_type n ) { base() += n; }
		
		template <class Iterator>
		bool operator== (const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
		{
			lhs.base() == rhs.base();
		}
		
		template <class Iterator>
		bool operator!= (const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
		{
			lhs.base() != rhs.base();
		}
		
		template <class Iterator>
		bool operator<  (const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
		{
			lhs.base() > rhs.base();
		}
		template <class Iterator>
		bool operator<= (const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
		{
			lhs.base() >= rhs.base();
		}
		
		template <class Iterator>
		bool operator>  (const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
		{
			lhs.base() < rhs.base();
		}
		
		template <class Iterator>
		bool operator>= (const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
		{
			lhs.base() <= rhs.base();
		}

		~reverse_iterator() { }
	};
}

#endif
