/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:48:21 by emtran            #+#    #+#             */
/*   Updated: 2023/02/02 14:18:55 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <algorithm>
# include <iostream>
# include <string.h>
# include <limits>
# include <utility>
# include <cstddef>
# include <stddef.h>
# include <stdio.h>
# include <memory>
# include <vector>
# include "colors.hpp"

#if STD
	#define _NAMESPACE	"STD"
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#define _NAMESPACE	"FT"
	#include "../includes/containers/map.hpp"
	#include "../includes/containers/stack.hpp"
	#include "../includes/containers/vector.hpp"
	#include "../includes/iterators/iterator_traits.hpp"
	#include "../includes/iterators/iterator.hpp"
	#include "../includes/iterators/random_access_iterator.hpp"
	#include "../includes/iterators/reverse_iterator.hpp"
	#include "../includes/RBT/node.hpp"
	#include "../includes/RBT/RBiterator.hpp"
	#include "../includes/RBT/RBtree.hpp"
	#include "../includes/std_functions/enable_if.hpp"
	#include "../includes/std_functions/equal.hpp"
	#include "../includes/std_functions/is_integral.hpp"
	#include "../includes/std_functions/lexicographical_compare.hpp"
	#include "../includes/std_functions/pair.hpp"
#endif


/*			B E A U T Y			*/

void    intro_std_functions();
void 	title_of_test(const std::string& s);
void 	title_of_function(const std::string& s);


/*			E Q U A L			*/

void	test_equal();
	void 	is_palindrome(const std::string& s);
	void 	is_same_equal(const std::string &s1, const std::string &s2);


/*			L E X I C O G R A P H I C A L    C O M P A R E			*/

void test_lexicographical_compare();
	void is_same_lexico_compare(const std::string &s1, const std::string &s2);


/*			I S _ I N T E G R A L		*/

void	test_is_integral();


/*			P A I R  &  M A K E _ P A I R		*/

void	test_make_pair();


/*			E N A B L E _ I F		*/

void	test_enable_if();




void	compare_and_print(size_t p1, size_t p2);

template <class InputIterator1, class InputIterator2>
void	compare_vector_and_print(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

int 	test_vector();

void	test_map();

#endif
