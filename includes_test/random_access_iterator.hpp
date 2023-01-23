/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:34:43 by emtran            #+#    #+#             */
/*   Updated: 2023/01/23 19:29:52 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace	ft {

	template <class It>
	class random_access_iterator {

		public:
			// typedef It iterator_type;
			typedef typename ft::iterator_traits<It*>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<It*>::value_type 			value_type;
			typedef typename ft::iterator_traits<It*>::difference_type 		difference_type;
			typedef typename ft::iterator_traits<It*>::pointer 				pointer;
			typedef typename ft::iterator_traits<It*>::reference 			reference;

			/*			CONSTRUCTORS		*/

			random_access_iterator() : current(NULL) {};

			random_access_iterator(pointer x) : current(x) {};

			template<class U>
			random_access_iterator(const random_access_iterator<U>& other) : current(other.base()) {};

			/*			BASE			*/

			pointer base() const{

				return (current);
			}

			/*			OPERATORS =			*/

			template <class U>
			random_access_iterator& operator=(const random_access_iterator<U>& other) {
				current = other.base();
				return (*this);
			}

			/*			OPERATORS POINTED-TO ELEMENT			*/

			reference operator*() const {

				return (*current);
			}

			pointer operator->() const {

				return (&(operator*()));
			}

			/*			OPERATORS TO ACCESS INDEX			*/

			reference	operator[](difference_type n) {

				return (current[n]);
			}

			/*			OPERATORS TO (IN)(DE)CREMENT			*/

			random_access_iterator&	operator++(){
				++current;
				return(*(this));
			}

			random_access_iterator&	operator--(){
				--current;
				return(*(this));
			}

			random_access_iterator	operator++(int){

				random_access_iterator tmp = *(this);
				current++;
				return (tmp);
			}

			random_access_iterator	operator--(int){

				random_access_iterator tmp = *(this);
				current--;
				return (tmp);
			}

			random_access_iterator	operator+(difference_type n) const{

				return (current + n);
			}

			random_access_iterator	operator-(difference_type n) const{

				return (current - n);
			}

			random_access_iterator&	operator+=(difference_type n){

				current += n;
				return (*this);
			}

			random_access_iterator&	operator-=(difference_type n){

				current -= n;
				return (*this);
			}
		protected:
			pointer current;
	};

	/*			OPERATORS TO COMPARE			*/

	template<class It1, class It2>
	bool	operator==(const ft::random_access_iterator<It1>& lhs,
						const ft::random_access_iterator<It2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template<class It1, class It2>
	bool	operator!=(const ft::random_access_iterator<It1>& lhs, \
						const ft::random_access_iterator<It2>& rhs) {

		return (lhs.base() != rhs.base());
	}

	template<class It1, class It2>
	bool 	operator<(const ft::random_access_iterator<It1>& lhs, \
						const ft::random_access_iterator<It2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template<class It1, class It2>
	bool 	operator<=(const ft::random_access_iterator<It1>& lhs, \
						const ft::random_access_iterator<It2>& rhs) {

		return (lhs.base() <= rhs.base());
	}

	template<class It1, class It2>
	bool 	operator>(const ft::random_access_iterator<It1>& lhs, \
						const ft::random_access_iterator<It2>& rhs) {

		return (lhs.base() > rhs.base());
	}

	template<class It1, class It2>
	bool 	operator>=(const ft::random_access_iterator<It1>& lhs, \
						const ft::random_access_iterator<It2>& rhs) {

		return (lhs.base() >= rhs.base());
	}


	/*			OPERATORS TO ADVANCE THE ITERATOR			*/

	template<class It>
	random_access_iterator<It>	operator+(typename random_access_iterator<It>::difference_type n, \
               						const random_access_iterator<It>& it) {

		return (random_access_iterator<It>(it.base() - n));
	}


	/*			OPERATORS TO COMPUTE THE DISTANCE BETWEEN TWO ITERATOR ADAPTORS			*/

	template<class It1, class It2>
	typename random_access_iterator<It1>::difference_type	operator-(const random_access_iterator<It1>& lhs, \
               												const random_access_iterator<It2>& rhs) {

		return (rhs.base() - lhs.base());
	}
}
#endif
