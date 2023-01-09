/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_std_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:43:25 by emtran            #+#    #+#             */
/*   Updated: 2023/01/09 15:20:12 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.hpp"

class BoBun{};

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
    is_palindrome("esope reste ici et se repose");
    is_palindrome("esope reste ici etser epose");

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

    title_of_function("Lexicographical_Compare");

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

void    test_is_integral() {

    title_of_function("Is_Integral");

    title_of_test("Test d'intégrité");
    #if STD
        std::cout << PINK << "Class BoBun" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<BoBun>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Int" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<int>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Const Int" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<const int>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Volatile Int" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<volatile int>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Char" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<char>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Int*" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<int*>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Bool" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<bool>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Wchar_t" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<wchar_t>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Short" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<short>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Long" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<long>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Long Long" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<long long>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Float" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<float>::is_integer ? "True" : "False") << RESET << std::endl;
        std::cout << "\n\n";
    #else
        std::cout << PINK << "Class BoBun" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<BoBun>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Int" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<int>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Const Int" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<const int>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Volatile Int" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<volatile int>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Char" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<char>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Int*" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<int*>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Bool" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<bool>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Wchar_t" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<wchar_t>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Short" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<short>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Long" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<long>::value ? "True" : "False") << RESET <<  std::endl;
        std::cout << PINK << "Long Long" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<long long>::value ? "True" : "False") << RESET << std::endl;
        std::cout << PINK << "Float" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<float>::value ? "True" : "False") << RESET << std::endl;
        std::cout << "\n\n";
    #endif
}

/*********************************************************
 *														 *
 *		P A I R  &  M A K E _ P A I R   				 *
 *														 *
 *********************************************************/

void    test_make_pair() {

    title_of_function("Pair & Make_Pair");

    title_of_test("Test de Tournez Manège !!!");
    const char* ingrid = "Ingrid";
    const char* partenaires[5] = {"Robert", "Bien-Aimé", "Khaled", "Jean-Eudes", "Brandon"};
    (void) ingrid;
    (void) partenaires;
    // //std::vector<ft::pair<const char*, const char*>> couple;
    // for (unsigned int i = 0; i < 5; i++) {

    //     std::cout << "Les partenaires de l'émission qui vont essayer de se séduire sont : "
    //             << PINK << couple.first << RESET << " et " << GREEN << couple.second
    //             << RESET << std::endl;
    // }

}


/*********************************************************
 *														 *
 *		E N A B L E _ I F               				 *
 *														 *
 *********************************************************/

void    test_enable_if () {

    title_of_function("Enable_if");

    title_of_test("Test de la queue de poisson");
}
