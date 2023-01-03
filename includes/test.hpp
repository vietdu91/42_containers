/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:48:21 by emtran            #+#    #+#             */
/*   Updated: 2023/01/03 19:38:33 by emtran           ###   ########.fr       */
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
#endif

#include <algorithm>
#include <iostream>
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

#endif
