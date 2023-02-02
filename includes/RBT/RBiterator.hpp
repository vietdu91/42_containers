/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBiterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:53:28 by emtran            #+#    #+#             */
/*   Updated: 2023/02/02 14:37:23 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBITERATOR_HPP
# define RBITERATOR_HPP

# include "../iterators/iterator_traits.hpp"
# include "../iterators/iterator.hpp"

namespace ft {

	template <class Pair, class Node>
	struct	RBiterator :  public ft::iterator<std::bidirectional_iterator_tag, Pair> {

		public:

			typedef	Pair&		reference;
			typedef	const Pair&	const_reference;
			typedef	Pair*		pointer;
			typedef	const Pair*	const_pointer;

		private:

			Node*	_node;

		public:

			// **********************************************
			// ================ Constructors ================
			// **********************************************

			RBiterator() : _node(NULL) {};

			template<class other_Node>
			explicit RBiterator(other_Node* other): _node(other){};

			template<class other_Pair, class other_Node>
			RBiterator(RBiterator<other_Pair, other_Node> const& x) : _node(x.base()) {};


			// ****************************************************
			// ================    Copy Assign.    ================
			// ****************************************************

			template<class other_Pair, class other_Node>
			RBiterator& operator=(RBiterator<other_Pair const, other_Node> const& x) {

				if (this != &x)
					this->_node = x._node;

				return (*this);

			}


			// ****************************************************
			// ====================    Base    ====================
			// ****************************************************

			Node* base() const {

				return (_node);

			}


			// ****************************************************
			// =================    Operators     =================
			// ****************************************************

			reference operator*() {

				return (_node->value);

			}

			const_reference operator*() const {

				return (_node->value);

			}

			pointer operator->() {

				return (&this->_node->value);

			}

			const_pointer operator->() const {

				return (&this->_node->value);

			}

			RBiterator&	operator++() {

				if (!(_node->right->is_null())) {

					_node = _node->right;

					while (!(_node->left->is_null()))
						_node = _node->left;

				}

				else {

					while (!(_node->parent->is_null()) && _node == _node->parent->right)
						_node = _node->parent;

					_node = _node->parent;
				}

				return (*this);

			}

			RBiterator	operator++(int) {

				RBiterator tmp(*this);
				++(*this);

				return (tmp);

			}

			RBiterator&	operator--() {

				if (!(_node->left->is_null())){

					_node = _node->left;

					while (!(_node->right->is_null()))
						_node = _node->right;

				}

				else {

					while (!(_node->parent->is_null()) && _node == _node->parent->left)
						_node = _node->parent;

					_node = _node->parent;

				}

				return (*this);
			}

			RBiterator	operator--(int) {

				RBiterator tmp(*this);
				--(*this);

				return (tmp);

			}
	};

	template <class P1, class N1, class P2, class N2>
	bool	operator==(const RBiterator<P1, N1>& it1, const RBiterator<P2, N2>& it2) {

		return (it1.base() == it2.base());

	}

	template <class P1, class N1, class P2, class N2>
	bool	operator!=(const RBiterator<P1, N1>& it1, const RBiterator<P2, N2>& it2) {

		return (!(it1 == it2));

	}
}

#endif
