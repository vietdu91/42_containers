/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:34:55 by emtran            #+#    #+#             */
/*   Updated: 2023/01/23 20:08:39 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <vector>

// A MODIFIER : <vector> vers notre vector implemente

namespace ft {

	template< class T, class Container = std::vector<T> >
	class stack {

		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;

			/*		CONSTRUCTORS	*/

			explicit stack(const Container& cont = Container()) {

				this->c = cont;
				return;
			}

			/*		DECONSTRUCTOR	*/

			~stack() {

				return;
			}

			/*		COPY CONSTRUCTOR	*/

			stack(const	stack& other) {

				this->c = other.c;
				return;
			}

			/*		COPY ASSIGNMENT		*/

			stack& operator=(const stack& other) {

				this->c = other.c;
				return (*this);
			}

			/*		TOP		*/
			/*		Obtenir l'element au top de la stack	*/

			reference top() {

				return (c.back());
			}

			const_reference top() const {

				return (c.back());
			}

			/*		ERASE		*/
			/*		Checker si la stack est	vide	*/

			bool	empty() const {

				return (this->c.empty());
			}

			/*		SIZE		*/
			/*		Retourner le nombre d'elements		*/

			size_type	size() const {

				return (this->c.size());
			}

			/*		PUSH		*/
			/*		Pusher un element sur le top de la stack	*/

			void	push(const value_type& value) {

				return (this->c.push_back(value));
			}

			/*		POP		*/
			/*		Enleves l'element au top de la stack	*/

			void	pop() {

				return (this->c.pop_back());
			}

			protected:
				Container	c;

		friend bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

			 return (lhs.c == rhs.c);
		};

		friend bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

			 return (lhs.c != rhs.c);
		};

		friend bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

			 return (lhs.c < rhs.c);
		};

		friend bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

			 return (lhs.c <= rhs.c);
		};

		friend bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)  {

			 return (lhs.c > rhs.c);
		};

		friend bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

			 return (lhs.c >= rhs.c);
		};
	};
}

#endif
