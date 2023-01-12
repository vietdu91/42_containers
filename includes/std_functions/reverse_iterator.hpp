/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:05:55 by emtran            #+#    #+#             */
/*   Updated: 2023/01/12 18:50:17 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace	ft {

	template <class It>
	class reverse_iterator : public It {

		public:
			typedef It iterator_type;
			typedef typename ft::iterator_traits<It>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<It>::value_type 			value_type;
			typedef typename ft::iterator_traits<It>::difference_type 		difference_type;
			typedef typename ft::iterator_traits<It>::pointer 				pointer;
			typedef typename ft::iterator_traits<It>::reference 			reference;

			/*			CONSTRUCTORS		*/
			reverse_iterator() : current(It()) {};

			explicit reverse_iterator(iterator_type x) : current(x) {};

			template< class U >
			reverse_iterator(const reverse_iterator<U>& other) : current(other.base()) {};

			/*			BASE			*/
			iterator_type base() const{

				return (current);
			}

			/*			OPERATORS =			*/
			template <class U>
			reverse_iterator& operator=(const reverse_iterator<U>& other) {
				return (other.base());
			}

			/*			OPERATORS POINTED-TO ELEMENT			*/
			template <class U>
			reference operator*() const {

				It tmp = current;
				return *(--tmp);
			};

			template <class U>
			pointer operator->() const {

				return (&(operator*()));
			};

			/*			OPERATORS TO ACCESS INDEX			*/

			operator[](difference_type n) const{

				return (base()[-n-1])
			}

			/*			OPERATORS TO CREMENT			*/

			reverse_iterator&	operator++(){

				return(*(--this));
			}

			reverse_iterator&	operator--(){

				return(*(++this));
			}

			reverse_iterator	operator++(int){

				reverse_iterator tmp = *(--this);
				return (tmp);
			}

			reverse_iterator	operator--(int){

				reverse_iterator tmp = *(++this);
				return (tmp);
			}

			reverse_iterator	operator+(difference_type n) const{

				return (reverse_iterator(current - n))
			}

			reverse_iterator	operator-(difference_type n) const{

				return (reverse_iterator(current + n))
			}

			reverse_iterator&	operator+=(difference_type n){

				current -= n;
				return (*this)
			}

			reverse_iterator&	operator-=(difference_type n){

				current += n;
				return (*this)
			}

		protected:
			iterator_type current;
	};
}
#endif
