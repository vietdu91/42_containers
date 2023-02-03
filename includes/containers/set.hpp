/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:39:59 by emtran            #+#    #+#             */
/*   Updated: 2023/02/03 20:26:20 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <functional>
# include <memory>

# include "../std_functions/equal.hpp"
# include "../std_functions/lexicographical_compare.hpp"
# include "../std_functions/pair.hpp"
# include "../RBT/RBtree.hpp"
# include "../iterators/reverse_iterator.hpp"

namespace ft {

	template<class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set {

		private:

			typedef Node<const Key>											node_type;
			typedef typename Allocator::template rebind<node_type>::other 	node_allocator_type;

		public:

			typedef Key										key_type;
			typedef Key										value_type;
			typedef Compare									key_compare;
			typedef Compare									value_compare;
			typedef Allocator								allocator_type;
			typedef	typename std::size_t					size_type;
			typedef	typename std::ptrdiff_t					difference_type;

		private:

			typedef RBtree<value_type, allocator_type, value_compare>	tree_type;

		public:

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;

			typedef	ft::RBiterator<const value_type, node_type>	iterator;
			typedef	ft::RBiterator<const value_type, node_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		private:

			allocator_type	_alloc;
			key_compare     _key_comp;
			tree_type		_tree;

		public:

			// **********************************************
			// ================ Constructors ================
			// **********************************************

			explicit set() {}

			explicit set(const Compare& comp, const Allocator& alloc) :
				_alloc(alloc),
				_key_comp(comp),
				_tree(value_compare(comp), node_allocator_type(alloc)) {}

			template<class InputIt>
			set(InputIt first, InputIt last, const Compare& comp,const Allocator& alloc) :
				_alloc(alloc),
				_key_comp(comp),
				_tree(value_compare(comp), node_allocator_type(alloc)) {

				insert(first, last);
			}

			set(const set& other) : _alloc(other._alloc), _key_comp(other._key_comp), _tree(other._tree) {};


			// ****************************************************
			// ================    Copy Assign.    ================
			// ****************************************************

			set& operator=(set const& other) {

				if (this != &other) {

					_key_comp = other._key_comp;
					_tree = other._tree;
				}

				return (*this);

			}


			// **************************************************
			// ================    Allocator    =================
			// **************************************************

			allocator_type get_allocator() const {

				return (this->_tree.get_allocator());

			};


			// **************************************************
			// ================    Destructor    ================
			// **************************************************

			~set() {};


			// **************************************************
			// ================    Iterators    =================
			// **************************************************

			iterator	begin() {

				return (iterator(_tree.begin()));

			}

			const_iterator	begin() const {

				return (const_iterator(_tree.begin()));

			}

			iterator	end() {

				return (iterator(_tree.nil()));

			}

			const_iterator	end() const {

				return (const_iterator(_tree.nil()));

			}

			reverse_iterator	rbegin() {

				return (reverse_iterator(end()));

			}

			const_reverse_iterator	rbegin() const {

				return (const_reverse_iterator(end()));

			}

			reverse_iterator	rend() {

				return (reverse_iterator(begin()));

			}

			const_reverse_iterator	rend() const {

				return (const_reverse_iterator(begin()));

			}

			// **************************************************
			// =================    Capacity    =================
			// **************************************************

			bool	empty() const {

				return (_tree.size() == 0);
			}

			size_type	size() const {

				return (_tree.size());
			}

			size_type	max_size() const {

				return (_tree.get_allocator().max_size());

			}

			// **************************************************
			// =================    Modifiers    ================
			// **************************************************

			ft::pair<iterator, bool> insert(const value_type& value) {

				return (_tree.insert(value));

			}

			iterator insert(iterator position, const value_type& val) {

				(void)position;
				return (insert(val).first);

			}

			template<class InputIt>
			void insert(InputIt first, InputIt last) {

				for (InputIt it = first; it != last; it++)
					insert(*it);

			}

			void erase(iterator position) {

				if (position == end())
					return;

				_tree.deleteNode(*position);

			}

			size_type erase(const key_type& k) {

				iterator position = find(k);

				if (position == end())
					return (0);

				erase(position);
				return (1);

			}

			void erase(iterator first, iterator last) {

				if (first == begin() && last == end()) {

					clear();
					return;
				}

				iterator it = first;
				iterator eraser;

				while (it != last) {

					eraser = it;
					it++;
					erase(eraser);
				}

			}

			void	clear() {

				_tree.clear();

			}

			void	swap(set& other) {

				key_compare		tmp;

				_tree.swap(other._tree);

				tmp = other._key_comp;
				_key_comp = other._key_comp;
				other._key_comp = tmp;

			}


			// **************************************************
			// =================    Observers    ================
			// **************************************************

			key_compare key_comp() const {

				return (_key_comp);

			}

			value_compare value_comp() const {

				return(_tree.comp());

			}


			// **************************************************
			// ==================    Look Up    =================
			// **************************************************

			iterator	find(const key_type& k) {

				return (_find<iterator>(k));
			}

			const_iterator	find(const key_type& k) const {

				return (_find<const_iterator>(k));
			}

			template <class It>
			It	_find(const key_type& k) const {

				node_type*	node = _tree.root();

				while (!node->is_null()) {

					if (_key_comp(k, node->value.first))
						node = node->left;
					else if (_key_comp(node->value.first, k))
						node = node->right;
					else
						break;
				}

				return (It(node));
			}

			size_type	count(const key_type& k) const {

				iterator position = begin();

				for (; position != end(); position++) {

					if ((*position).first == k)
						break;
				}

				if (position == end())
					return (0);
				return (1);
			}

			iterator lower_bound(const key_type& k) {

				iterator first = begin();

				for (; first != end(); first++) {

					if (!_key_comp((*first).first, k))
						break;
				}

				return (first);

			}

			const_iterator lower_bound(const key_type& k) const {

				iterator first = begin();

				for (; first != end(); first++){

					if (!_key_comp((*first).first, k))
						break;
				}

				return (const_iterator(first));

			}

			iterator upper_bound(const key_type& k) {

				iterator first = begin();

				for (; first != end(); first++) {

					if (_key_comp(k,(*first).first))
						break;
				}

				return (first);

			}

			const_iterator upper_bound(const key_type& k) const {

				iterator first = begin();

				for (; first != end(); first++){

					if (_key_comp(k, (*first).first))
						break;
				}

				return (const_iterator(first));

			}

			ft::pair<iterator,iterator> equal_range(const Key& key) {

				return (ft::make_pair(lower_bound(key), upper_bound(key)));

			}

			ft::pair<const_iterator,const_iterator> equal_range(const Key& key) const {

				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

	};

	template<class Key, class Compare, class Alloc>
	void swap(ft::set<Key,Compare,Alloc>& lhs,ft::set<Key,Compare,Alloc>& rhs) {

		lhs.swap(rhs);

	}

	template<class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key,Compare,Alloc>& lhs,const ft::set<Key,Compare,Alloc>& rhs) {

		return ((&lhs == &rhs) || ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())));

	}

	template<class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {

		return (!(lhs == rhs));

	}

	template<class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key,Compare,Alloc>& lhs,const ft::set<Key,Compare,Alloc>& rhs) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));

	}

	template<class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key,Compare,Alloc>& lhs,const ft::set<Key,Compare,Alloc>& rhs) {

		return (rhs < lhs);

	}

	template<class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key,Compare,Alloc>& lhs,const ft::set<Key,Compare,Alloc>& rhs) {

		return (!(lhs > rhs));

	}

	template<class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key,Compare,Alloc>& lhs,const ft::set<Key,Compare,Alloc>& rhs) {

		return (!(lhs < rhs));

	}

};

#endif
