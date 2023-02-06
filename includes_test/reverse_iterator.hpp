/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:05:55 by emtran            #+#    #+#             */
/*   Updated: 2023/02/03 20:37:00 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace	ft {

	template <class It>
	class reverse_iterator : public It {

		public:
			typedef It iterator_type;
			typedef typename iterator_traits<It>::iterator_category 	iterator_category;
			typedef typename iterator_traits<It>::value_type 			value_type;
			typedef typename iterator_traits<It>::difference_type 		difference_type;
			typedef typename iterator_traits<It>::pointer 				pointer;
			typedef typename iterator_traits<It>::reference 			reference;

			/*			CONSTRUCTORS		*/

			reverse_iterator() : current(iterator_type()) {};

			explicit reverse_iterator(iterator_type x) : current(x) {};

			template<class U>
			reverse_iterator(const reverse_iterator<U>& other) : current(other.base()) {};

			reverse_iterator(const reverse_iterator& other) : current(other.base()) {};

			/*			BASE			*/

			iterator_type base() const{

				return (current);
			}

			/*			OPERATORS =			*/

			reverse_iterator& operator=(const reverse_iterator& other) {

				this->current = other.base();
				return (*this);
			}

			/*			OPERATORS POINTED-TO ELEMENT			*/

			reference operator*() const {

				It tmp = current;
				return *(--tmp);
			}

			pointer operator->() const {

				return (&(**this));
			}

			/*			OPERATORS TO ACCESS INDEX			*/

			reference	operator[](difference_type n) const {

				return (*(*this + n));
			}

			/*			OPERATORS TO (IN)(DE)CREMENT			*/

			reverse_iterator&	operator++(){
				--current;
				return(*(this));
			}

			reverse_iterator&	operator--(){
				++current;
				return(*(this));
			}

			reverse_iterator	operator++(int){

				reverse_iterator tmp(*this);
				--current;
				return (tmp);
			}

			reverse_iterator	operator--(int){

				reverse_iterator tmp(*this);
				++current;
				return(tmp);
			}

			reverse_iterator	operator+(difference_type n) const{

				return (reverse_iterator(current - n));
			}

			reverse_iterator	operator-(difference_type n) const{

				return (reverse_iterator(current + n));
			}

			reverse_iterator&	operator+=(difference_type n){

				current -= n;
				return (*this);
			}

			reverse_iterator&	operator-=(difference_type n){

				current += n;
				return (*this);
			}

		protected:
			iterator_type current;
	};

	/*			OPERATORS TO COMPARE			*/

	template<class It1, class It2>
	bool	operator==(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template<class It1, class It2>
	bool	operator!=(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() != rhs.base());
	}

	template<class It1, class It2>
	bool 	operator<(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() > rhs.base());
	}

	template<class It1, class It2>
	bool 	operator<=(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() >= rhs.base());
	}

	template<class It1, class It2>
	bool 	operator>(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template<class It1, class It2>
	bool 	operator>=(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() <= rhs.base());
	}


	/*			OPERATORS TO ADVANCE THE ITERATOR			*/

	template<class It>
	reverse_iterator<It>	operator+(typename reverse_iterator<It>::difference_type n, \
               						const reverse_iterator<It>& it) {

		return (it + n);
	}


	/*			OPERATORS TO COMPUTE THE DISTANCE BETWEEN TWO ITERATOR ADAPTORS			*/

	template<class It1, class It2>
	typename reverse_iterator<It1>::difference_type	operator-(const reverse_iterator<It1>& lhs, \
               												const reverse_iterator<It2>& rhs) {

		return (rhs.base() - lhs.base());
	}

	template<class It1>
	typename reverse_iterator<It1>::difference_type	operator-(const reverse_iterator<It1>& lhs, \
               												const reverse_iterator<It1>& rhs) {

		return (rhs.base() - lhs.base());
	}

}

#endif
