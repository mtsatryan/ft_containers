/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:29:12 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/12/26 15:29:17 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "ft_containers.hpp"

namespace ft
{
    //REMOVE_CONST
    template <class T> struct remove_const { typedef T type; };
    template <class T> struct remove_const <const T> { typedef T type; };
            // Iterator
        template<typename IT>
        class RandomAccessIterator : public iterator<ft::random_access_iterator_tag, IT>
            {
                public:
                        typedef typename iterator<ft::random_access_iterator_tag, IT>::difference_type      difference_type;
                        typedef typename iterator<ft::random_access_iterator_tag, IT>::value_type           value_type;
                        typedef typename iterator<ft::random_access_iterator_tag, IT>::reference            reference;
                        typedef typename iterator<ft::random_access_iterator_tag, IT>::pointer              pointer;

                        typedef ft::random_access_iterator_tag                      iterator_category;
                    
                private:
                        pointer _p;

                public:

                        RandomAccessIterator() : _p() {}
                        RandomAccessIterator(pointer a) : _p(a) {}
                        RandomAccessIterator(const RandomAccessIterator &s) : _p(s.getPtr()) {}
                        RandomAccessIterator& operator=(const RandomAccessIterator &s) {
                            if (this != &s)
                                _p = s._p;
                            return *this;
                        }

                        pointer getPtr(void)
                        {
                            return (this->_p);
                        }
                        
                        pointer getPtr(void) const
                        {
                            return (this->_p);
                        }

                        
                        RandomAccessIterator& operator++(){
                            ++_p;
                            return *this;
                        }

                        RandomAccessIterator& operator--(){
                            --_p;
                            return *this;
                        }

                        RandomAccessIterator operator++(int){
                            RandomAccessIterator tmp(*this);
                            ++_p;
                            return tmp;
                        }

                        RandomAccessIterator operator--(int){
                            RandomAccessIterator tmp(*this);
                            --_p;
                            return tmp;
                        }

                        RandomAccessIterator operator+(const difference_type & d) const {
                            return _p + d;
                        }
                   
                        RandomAccessIterator operator-(const difference_type & d) const {
                            return _p - d;
                        }

                        RandomAccessIterator& operator+=(const difference_type & d) {
                            _p += d;
                            return *this;
                        }                        

                        RandomAccessIterator& operator-=(const difference_type & d) {
                            _p -= d;
                            return *this;
                        }

                        pointer operator->() const {
                            return _p;
                        }

                        reference operator*() const {
                            return *_p;
                        }

                        reference operator[](difference_type n) const {
                            return *(_p + n);
                        }
                        
                        operator RandomAccessIterator<const value_type> ()
                        {
                            return (RandomAccessIterator<const value_type>(getPtr()));
                        }
            
                        virtual ~RandomAccessIterator() {}
            };

        // Iterator non-member functions logical operations, + - operations
        template<typename X>
        RandomAccessIterator<X> operator+(const typename  RandomAccessIterator<X>::difference_type& a,
                                            const RandomAccessIterator<X>& i)
        { return (i + a); }

        template<typename X>
         RandomAccessIterator<X> operator-(const typename  RandomAccessIterator<X>::difference_type& a, const  RandomAccessIterator<X>& i){ return (i - a); }

        template<typename X, typename Y>
         typename  RandomAccessIterator<X>::difference_type operator-(const  RandomAccessIterator<X>& lhs, const  RandomAccessIterator<Y>& rhs){ return lhs.getPtr() - rhs.getPtr(); }

        template<typename X, typename Y>
         typename  RandomAccessIterator<X>::difference_type operator+(const  RandomAccessIterator<X>& lhs, const  RandomAccessIterator<Y>& rhs){ return lhs.getPtr() + rhs.getPtr(); }

        template <typename X, typename Y>
             bool operator==(const  RandomAccessIterator<X>& lhs, const  RandomAccessIterator<Y>& rhs){
                return lhs.getPtr() == rhs.getPtr();
            }
        
        template <typename X, typename Y>
             bool operator!=(const  RandomAccessIterator<X>& lhs, const  RandomAccessIterator<Y>& rhs){
                return lhs.getPtr() != rhs.getPtr();
            }

        template <typename X, typename Y>
             bool operator>(const  RandomAccessIterator<X>& lhs, const  RandomAccessIterator<Y>& rhs){
                return lhs.getPtr() > rhs.getPtr();
            }

        template <typename X, typename Y>
             bool operator<(const  RandomAccessIterator<X>& lhs, const  RandomAccessIterator<Y>& rhs){
                return lhs.getPtr() < rhs.getPtr();
            }
        
        template <typename X, typename Y>
             bool operator<=(const  RandomAccessIterator<X>& lhs, const  RandomAccessIterator<Y>& rhs){
                return lhs.getPtr() <= rhs.getPtr();
            }

        template <typename X, typename Y>
            bool operator>=(const  RandomAccessIterator<X>& lhs, const  RandomAccessIterator<Y>& rhs){
                return lhs.getPtr() >= rhs.getPtr();
            }
}

#endif
