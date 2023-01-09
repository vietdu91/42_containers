/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:48:21 by emtran            #+#    #+#             */
/*   Updated: 2023/01/09 15:35:38 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#if STD
	#define _NAMESPACE	"STD"
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#define _NAMESPACE	"FT"
	#include "../includes/std_functions/equal.hpp"
	#include "../includes/std_functions/lexicographical_compare.hpp"
	#include "../includes/std_functions/is_integral.hpp"
	#include "../includes/std_functions/pair.hpp"
	#include "../includes/std_functions/enable_if.hpp"
#endif

#include <algorithm>
#include <iostream>
#include <string.h>
#include <limits>
#include <utility>
#include <cstddef>
#include <memory>
#include "colors.hpp"

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


#endif
