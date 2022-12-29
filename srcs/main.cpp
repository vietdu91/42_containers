/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:48:56 by emtran            #+#    #+#             */
/*   Updated: 2022/12/29 19:24:28 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#endif

#include <algorithm>
#include <iostream>

bool is_palindrome(const std::string& s)
{
    return ft::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

void test(const std::string& s)
{
    std::cout << "\"" << s << "\" "
        << (is_palindrome(s) ? "is" : "is not")
        << " a palindrome\n";
}

int main()
{
    test("radar");
    test("hello");
	std::cout << _NAMESPACE << std::endl;
}
