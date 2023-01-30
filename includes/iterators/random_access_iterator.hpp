/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:34:43 by emtran            #+#    #+#             */
/*   Updated: 2023/01/26 16:34:08 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace	ft {

	template <class It>
	class random_access_iterator {

		public:
			// typedef It iterator_type;
			typedef typename ft::iterator_traits<It>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<It>::value_type 			value_type;
			typedef typename ft::iterator_traits<It>::difference_type 		difference_type;
			typedef typename ft::iterator_traits<It>::pointer 				pointer;
			typedef typename ft::iterator_traits<It>::reference 			reference;

			/*			CONSTRUCTORS		*/

			explicit random_access_iterator() : current(NULL) {};

			explicit random_access_iterator(pointer const x) : current(x) {};

			template<class U>
			random_access_iterator(const random_access_iterator<U>& other) : current(other.base()) {};

			random_access_iterator(const random_access_iterator& other){

				*this = other;
			};


			/*			BASE			*/

			const pointer base() const{

				return (current);
			}

			/*			OPERATORS =			*/

			random_access_iterator& operator=(const random_access_iterator& other) {

				current = other.base();
				return (*this);
			}

			/*			OPERATORS POINTED-TO ELEMENT			*/

			reference operator*() const {

				return (*current);
			}

			pointer operator->() const {

				return (current);
			}

			/*			OPERATORS TO ACCESS INDEX			*/

			reference	operator[](difference_type n) {

				return (current[n]);
			}

			/*			OPERATORS TO (IN)(DE)CREMENT			*/

			random_access_iterator&	operator++(){
				current++;
				return(*(this));
			}

			random_access_iterator&	operator--(){
				current--;
				return(*(this));
			}

			random_access_iterator	operator++(int){

				random_access_iterator tmp(*this);
				current++;
				return (tmp);
			}

			random_access_iterator	operator--(int){

				random_access_iterator tmp(*this);
				current--;
				return (tmp);
			}

			random_access_iterator	operator+(difference_type n) const{

				return (random_access_iterator(current + n));
			}

			difference_type	operator+(random_access_iterator n) const{

				return (current + n.current);
			}

			random_access_iterator	operator-(difference_type n) const{

				return (random_access_iterator(current - n));
			}

			difference_type	operator-(random_access_iterator n) const{

				return (current - n.current);
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

		return (random_access_iterator<It>(it.base() + n));
	}

	template<class It>
	random_access_iterator<It>	operator-(typename random_access_iterator<It>::difference_type n, \
               						const random_access_iterator<It>& it) {

		return (random_access_iterator<It>(it.base() - n));
	}

	/*			OPERATORS TO COMPUTE THE DISTANCE BETWEEN TWO ITERATOR ADAPTORS			*/

	template<class It1, class It2>
	typename random_access_iterator<It1>::difference_type	operator-(const random_access_iterator<It1>& lhs, \
               												const random_access_iterator<It2>& rhs) {

		return (lhs.base() - rhs.base());
	}

	template<class It1, class It2>
	typename random_access_iterator<It1>::difference_type	operator+(const random_access_iterator<It1>& lhs, \
               												const random_access_iterator<It2>& rhs) {

		return (lhs.base() + rhs.base());
	}
}
#endif
