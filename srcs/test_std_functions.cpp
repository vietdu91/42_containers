/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_std_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:43:25 by emtran            #+#    #+#             */
/*   Updated: 2023/01/03 19:18:19 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.hpp"

/*********************************************************
 *														 *
 *		E Q U A L										 *
 *														 *
 *********************************************************/

void is_same_equal(const std::string &s1, const std::string &s2) {

    std::cout << "\"" << s1 << "\" " << GREEN
        << (ft::equal(s1.begin(), s1.end(), s2.begin()) ? "is" : "is not")
        << RESET << " same that \""
        << s2
        << "\"\n";
}

void is_palindrome(const std::string& s) {

    std::cout << "\"" << s << "\" "
        << GREEN << (ft::equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) ? "is" : "is not")
        << RESET << " a palindrome\n";
}

void test_equal() {

    title_of_function("Equal");

    title_of_test("Test du Kayak");
    is_palindrome("radar");
    is_palindrome("hello");
    is_palindrome("cul");
    std::cout << "\n\n";

    title_of_test("Test du jumeau");
    is_same_equal("Patrick", "Patrick");
    is_same_equal("Patrick", "Patricia");
    is_same_equal("Patrick", "Patrick ");
    is_same_equal("Patrick", " Patrick");
    std::cout << "\n\n";
}


/*********************************************************
 *														 *
 *		L X G C L.   C O M P A R E						 *
 *														 *
 *********************************************************/

void is_same_lexico_compare(const std::string &s1, const std::string &s2) {

    std::cout << "\"" << s1 << "\" "
        << GREEN << (ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) ? "is" : "is not")
        << RESET << " lexicographically less than \""
        << s2
        << "\"\n";
}

void test_lexicographical_compare() {

    title_of_function("Lexicographical_compare");

    title_of_test("Test de l'astronaute");
    is_same_lexico_compare("Vide", "Vide");
    is_same_lexico_compare("Vide", "Vidange");
    is_same_lexico_compare("Vide", "Vide ");
    is_same_lexico_compare("Vide", " Vide");
    is_same_lexico_compare("Vi", "Vide");
    is_same_lexico_compare("Vide", "Vi");
    is_same_lexico_compare("", "🪐");
    is_same_lexico_compare("", "");
    std::cout << "\n\n";
}


/*********************************************************
 *														 *
 *		I S _ I N T E G R A L   						 *
 *														 *
 *********************************************************/
