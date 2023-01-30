/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:13:27 by emtran            #+#    #+#             */
/*   Updated: 2023/01/29 19:21:32 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# define BLACK false
# define RED   true

# include <iostream>
# include "./node.hpp"
# include "./RBiterator.hpp"


namespace ft {

	template <class Value, class Compare, class Allocator>
	class RBtree{

		public:

			typedef Value								value_type;
			typedef typename value_type::first_type		key_type;
			typedef Compare								value_compare;
			typedef Allocator							allocator_type;
			typedef	Node<value_type>					node_type;
			typedef typename allocator_type::size_type	size_type;
			typedef	RBiterator<value_type, node_type> 	iterator;
			typedef	node_type*							Nodeptr;

		private:

			allocator_type _alloc;
			Nodeptr	_TNULL;
			Nodeptr	_root;
			Nodeptr	_begin;
			Nodeptr	_end;
			value_compare _comp;
			size_type	_size;

		public:

			// **********************************************
			// ================ Constructors ================
			// **********************************************

			RBtree(value_compare const& comp, allocator_type const& alloc):
				_alloc(alloc),
				_TNULL(create_TNULL()),
				_root(_TNULL),
				_begin(_TNULL),
				_end(_TNULL),
				_comp(comp),
				_size(0) {}

			RBtree(RBtree const& other):
				_alloc(other._alloc),
				_TNULL(create_TNULL()),
				_root(_TNULL),
				_begin(_TNULL),
				_end(_TNULL),
				_comp(other.comp),
				_size(other._size) {

				_root = copy_tree(other, _TNULL);
			}


			// ****************************************************
			// ================    Copy Assign.    ================
			// ****************************************************

			RBtree&	operator=(RBtree const& other) {

				if (this != &other) {

					clear();
					_root = copy_tree(other, other._root, _TNULL);
					_size = other._size;

				}

				return (*this);
			}


			// **************************************************
			// ================    Destructor    ================
			// **************************************************

			~RBtree(){};


			// **************************************************
			// ================    Accessors     ================
			// **************************************************

			node_type* root() const {

				return _root;

			}

			node_type* begin() const {

				return _begin;

			}

			node_type* end() const {

				return _end;
			}

			value_compare const& comp() const {

				return _comp;

			}

			size_type size() const {

				return _size;

			}

			// **************************************************
			// ================    Cleaners      ================
			// **************************************************

			void	erase_tree(Nodeptr root) {

				if (root != _TNULL)
					return;

				erase_tree(root->left);
				erase_tree(root->right);
				root->deleteNode(root->value);

			}

			void	clear() {

				erase_tree(_root);
				_size = 0;
				_root = _TNULL;
				_begin = _TNULL;
				_end = _TNULL;

			}

			Nodeptr	create_TNULL() {

				Nodeptr new_node;

				new_node = _alloc.allocate(1);
				_alloc.construct(new_node, node_type());
				return (new_node);

			}

			Nodeptr	SearchParent(const value_type& value){
				Nodeptr	tmp = _root;
				Nodeptr	parent = tmp;

				while (tmp != _TNULL){
					parent = tmp;
					if (_comp(value, tmp->value))
						tmp = tmp->left;
					else if (!_comp(value, tmp->value))
						tmp = tmp->right;
					else
						return (NULL);
				}
				return (parent);
			}

			Nodeptr	minimum(Nodeptr root){
				Nodeptr	tmp= root;

				while (tmp->left && tmp->left != _TNULL)
					tmp = tmp->left;
				return(tmp);
			}

			Nodeptr	maximum(Nodeptr root){
				Nodeptr	tmp= root;

				while (tmp->right && tmp->right != _TNULL)
					tmp = tmp->right;
				return(tmp);
			}

			void	rotation_left(Nodeptr node){
				Nodeptr	parent;
				Nodeptr	child;

				child = node->right;
				parent = node->parent;

				node->right = child->left;
				if (child->left != _TNULL)
					child->left->parent = node;
				child->parent = parent;
				if (!parent)
					_root = child;
				else if (parent->left == node)
					parent->left = child;
				else
					parent->right = child;
				child->left = node;
				node->parent = child;
			}

			void	rotation_right(Nodeptr node){
				Nodeptr	parent;
				Nodeptr	child;

				child = node->left;
				parent = node->parent;

				node->left = child->right;
				if (child->right != _TNULL)
					child->right->parent = node;
				child->parent = parent;
				if (!parent)
					_root = child;
				else if (parent->left == node)
					parent->left = child;
				else
					parent->right = child;
				child->right = node;
				node->parent = child;
			}


			Nodeptr	getUncle(Nodeptr parent){
				Nodeptr grandparent = parent->parent;

				if (grandparent->left == parent)
					return (grandparent->right);
				else if (grandparent->right == parent)
					return (grandparent->left);
				return (NULL);
			}

			ft::pair<iterator, bool>	insert(const value_type& value){
				Nodeptr new_node = NULL;
				Nodeptr	parent = NULL;

				parent = SearchParent(value);
				if (parent == _TNULL){
					new_node = _alloc.allocate(1);
					_alloc.construct(new_node, node_type(NULL, value));
					new_node->left = _TNULL;
					new_node->right = _TNULL;
					new_node->color = BLACK;
					_root = new_node;
					return (ft::make_pair(iterator(new_node), true));
				}
				else if (!_comp(value,parent->value) && !_comp(parent->value, value))
					return (ft::make_pair(iterator(parent), false)); // TO DO verifier

				new_node = _alloc.allocate(1);
				_alloc.construct(new_node, node_type(parent, value));
				new_node->left = _TNULL;
				new_node->right = _TNULL;
				if (_comp(value,parent->value))
					parent->left = new_node;
				else
					parent->right = new_node;
				fix_properties(new_node);
				_begin = minimum(_root);
				_end = maximum(_root);
				_size++;
				return (ft::make_pair(iterator(new_node), true));
			}

			void	fix_properties(Nodeptr	node){
				Nodeptr	parent = node->parent;
				Nodeptr	uncle = NULL;
				Nodeptr	grandparent = NULL;

				if (!parent){
					node->color = BLACK;
					return ;
				}

				if (parent->color== BLACK)
					return;

				grandparent = parent->parent;
				if (!grandparent){
					parent->color = BLACK;
					_root = parent;
					return;
				}
				uncle = getUncle(parent);
				if (uncle && uncle != _TNULL && uncle->color == RED){
					parent->color = BLACK;
					grandparent->color = RED;
					uncle->color = BLACK;
					fix_properties(grandparent);
				}
				else if (parent == grandparent->left){
					if (node == parent->right){
						rotation_left(parent);
						parent = node;
					}
					rotation_right(grandparent);

					parent->color = BLACK;
					grandparent->color = RED;
				}
				else{
					if (node == parent->left) {
						rotation_right(parent);
						parent = node;
					}
					rotation_left(grandparent);
					parent->color = BLACK;
					grandparent->color = RED;
				}
			}

			void	transplant(Nodeptr node, Nodeptr new_child){
				Nodeptr	parent = node->parent;

				if (parent == NULL)
					_root = new_child;
				else if (parent->left == node)
					parent->left = new_child;
				else
					parent->right = new_child;
				new_child->parent = parent;
			}

			void deleteFix(Nodeptr x) {
				Nodeptr s;
				while (x != _root && x->color == BLACK) {
					if (x == x->parent->left) {
						s = x->parent->right;
						if (s->color == RED) {
							s->color = BLACK;
							x->parent->color = RED;
							rotation_left(x->parent);
							s = x->parent->right;
						}

						if (s->left->color == BLACK && s->right->color == BLACK) {
							s->color = RED;
							x = x->parent;
						}
						else {
							if (s->right->color == BLACK) {
								s->left->color = BLACK;
								s->color = RED;
								rotation_right(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							rotation_left(x->parent);
							x = _root;
						}
					}
					else {
						s = x->parent->left;
						if (s->color == RED) {
							s->color = BLACK;
							x->parent->color = RED;
							rotation_right(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == BLACK && s->right->color == BLACK) {
							s->color = RED;
							x = x->parent;
						}
						else {
							if (s->left->color == BLACK) {
								s->right->color = BLACK;
								s->color = RED;
								rotation_left(s);
								s = x->parent->left;
							}

							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							rotation_right(x->parent);
							x = _root;
						}
					}
				}
				x->color = BLACK;
			}

			void	deleteNode(value_type& value){
				Nodeptr	tmp = _root;
				Nodeptr	node = _TNULL;
				Nodeptr	min, fix;
				bool		og_color;

				while (tmp != _TNULL){
					if (!_comp(tmp->value, value) && !_comp(value, tmp->value)) {
						node = tmp;
					}

					if (_comp(tmp->value, value) || (!_comp(tmp->value, value) && !_comp(value, tmp->value))) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}

				if (node == _TNULL){
					std::cout << "NO FOUND" << std::endl;
					return;
				}

				min = node;
				og_color = min->color;
				if (node->left == _TNULL) {
					fix = node->right;
					transplant(node, node->right);
				}
				else if (node->right == _TNULL) {
					fix = node->left;
					transplant(node, node->left);
				}
				else {
					min = minimum(node->right);
					og_color = min->color;
					fix = min->right;
					if (min->parent == node) {
						fix->parent = min;
					}
					else {
						transplant(min, min->right);
						min->right = node->right;
						min->right->parent = min;
					}

					transplant(node, min);
					min->left = node->left;
					min->left->parent = min;
					min->color = node->color;
				}
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);

				if (og_color == BLACK) {
					deleteFix(fix);
				}
				_begin = minimum(_root);
				_end = maximum(_root);
				--_size;
			}

			void	swap(RBtree &other)
			{
				RBtree tmp;

				tmp._alloc = this->_alloc;
				tmp._comp = this->_comp;
				tmp._size = this->_size;
				tmp._root = this->_root;
				tmp._begin = this->_begin;
				tmp._end = this->_end;
				tmp._TNULL = this->_TNULL;

				this->_alloc = other._alloc;
				this->_comp = other._comp;
				this->_size = other._size;
				this->_root = other._root;
				this->_begin = other._begin;
				this->_end = other._end;
				this->_TNULL = other._TNULL;

				other._alloc = tmp._alloc;
				other._comp = tmp._comp;
				other._size = tmp._size;
				other._root = tmp._root;
				other._begin = tmp._begin;
				other._end = tmp._end;
				other._TNULL = tmp._TNULL;
			}

			allocator_type	get_allocator() const{
				return (_alloc);
			}

			Nodeptr	copy_tree(const RBtree& other, Nodeptr current_node,Nodeptr parent){
				Nodeptr new_node;

				if (current_node == _TNULL)
					return (_TNULL);

				new_node = _alloc.allocate(1);
				_alloc.construct(new_node, node_type(parent, _root->pair));

				if (current_node == other._begin)
					_begin = new_node;
				if (current_node == other._end)
					_end = new_node;
				if (current_node == other.current_node)
					_root = new_node;
				new_node->left = copy_tree(other, current_node->left, new_node);
				new_node->right = copy_tree(other, current_node->right, new_node);
				new_node->color = current_node->color;
				return (new_node);
			}
		// bool	check_rule_1(Node *_root){
		// 	if (root->color == BLACK)
		// 		return (true);
		// 	else
		// 		return (false);
		// }

		// int	check_rule_2(Node *root){
		// 	if (root == TNULL)
		// 		return (1);
		// 	int left_child = check_rule_2(root->left);
		// 	int right_child = check_rule_2(root->right);
		// 	if (left_child == -1 || right_child == -1 || (root->color == RED && ((root->left->color == RED) || (root->right->color == RED))))
		// 		return (-1);
		// 	return (1);
		// }

		// int check_rule_3(Node *root)
		// {
		// 	if (root == TNULL)
		// 		return (0);

		// 	int left_child = check_rule_3(root->left);
		// 	int right_child = check_rule_3(root->right);
		// 	if (left_child == -1 || right_child == -1 || left_child != right_child)
		// 		return (-1);
		// 	else
		// 		return (left_child + (root->color == BLACK ? 1 : 0));
		// }

		// void	check_rules(){
		// 	if (check_rule_1(root) && check_rule_2(root) == 1 && check_rule_3(root) >= 1)
		// 		std::cout <<"[OK]" << std::endl;
		// 	else
		// 		std::cout <<"[KO]"<< std::endl;
		// }

		void print2DUtil(Nodeptr root, int space)
		{
			// Base case
			if (root == _TNULL)
				return;

			// Increase distance between levels
			space += 10;

			// Process right child first
			print2DUtil(root->right, space);

			// Print current node after space
			// count
			std::cout << std::endl;
			for (int i = 10; i < space; i++)
				std::cout << " ";
			std::cout << root->value.first << "["<< (root->color == true ? "R" : "B")<<"]" << "\n";

			// Process left child
			print2DUtil(root->left, space);
		}

		void	print_tree(){
			print2DUtil(_root, 0);
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}

		// void	tree_to_list(Nodeptr node){
		// 	if (node == TNULL)
		// 		return;
		// 	tree_to_list(node->left);
		// 	std::cout <<"[" << node->value << "] ";
		// 	tree_to_list(node->right);
		// 	return;
		// }

		// void	test(){
		// 	tree_to_list(root);
		// 	std::cout << std::endl;
		// }
	};
}

#endif
