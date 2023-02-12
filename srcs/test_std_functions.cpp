/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_std_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:43:25 by emtran            #+#    #+#             */
/*   Updated: 2023/02/12 16:27:17 by emtran           ###   ########.fr       */
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

    //
    //  TEST DU KAYAK
    //

    title_of_test("Test du Kayak");

    //  RADAR
    std::cout << WHITE_B << "1. " << RESET;
    std::string str = "radar";
    if (ft::equal(str.begin(), str.begin() + str.size()/2, str.rbegin()))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    is_palindrome(str);

    //  HELLO
    std::cout << WHITE_B << "2. " << RESET;
    str = "hello";
    if (ft::equal(str.begin(), str.begin() + str.size()/2, str.rbegin()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_palindrome(str);

    //  CUL
    std::cout << WHITE_B << "3. " << RESET;
    str = "cul";
    if (ft::equal(str.begin(), str.begin() + str.size()/2, str.rbegin()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_palindrome(str);

    //  ESOPE ET SE REPOSE
    std::cout << WHITE_B << "4. " << RESET;
    str = "esope reste ici et se repose";
    if (ft::equal(str.begin(), str.begin() + str.size()/2, str.rbegin()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_palindrome(str);

    //  ESOPE ETSER REPOSE
    std::cout << WHITE_B << "5. " << RESET;
    str = "esope reste ici etser epose";
    if (ft::equal(str.begin(), str.begin() + str.size()/2, str.rbegin()))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    is_palindrome(str);

    std::cout << "\n\n";

    //
    //  TEST DU JUMEAU
    //

    title_of_test("Test du jumeau");

    std::string str1 = "Patrick";

    //  1
    std::cout << WHITE_B << "1. " << RESET;

    std::string str2 = "Patrick";
    if (ft::equal(str1.begin(), str1.end(), str2.begin()))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    is_same_equal(str1, str2);

    //  2
    std::cout << WHITE_B << "2. " << RESET;

    str2 = "Patricia";
    if (ft::equal(str1.begin(), str1.end(), str2.begin()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_same_equal(str1, str2);

    //  3
    std::cout << WHITE_B << "3. " << RESET;

    str2 = "Patrick ";
    if (ft::equal(str1.begin(), str1.end(), str2.begin()))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    is_same_equal(str1, str2);

    //  4
    std::cout << WHITE_B << "4. " << RESET;

    str2 = " Patrick";
    if (ft::equal(str1.begin(), str1.end(), str2.begin()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_same_equal(str1, str2);

    //  5
    std::cout << WHITE_B << "5. " << RESET;

    str2 = "Pat";
    if (ft::equal(str1.begin(), str1.end(), str2.begin()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_same_equal(str1, str2);

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

    //
    //  TEST DE L'ASTRONAUTE
    //

    title_of_test("Test de l'astronaute");

   std::string str1 = "Vide";

    //  1
    std::cout << WHITE_B << "1. " << RESET;

    std::string str2 = "Vide";
    if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_same_lexico_compare(str1, str2);

    //  2
    std::cout << WHITE_B << "2. " << RESET;

    str2 = "Vidange";
    if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_same_lexico_compare(str1, str2);

    //  3
    std::cout << WHITE_B << "3. " << RESET;

    str2 = "Vide ";
    if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    is_same_lexico_compare(str1, str2);

    //  4
    std::cout << WHITE_B << "4. " << RESET;

    str2 = " Vide";
    if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_same_lexico_compare(str1, str2);

    //  5
    std::cout << WHITE_B << "5. " << RESET;

    str1 = "Vi";
    str2 = "Vide";
    if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    is_same_lexico_compare(str1, str2);

    //  6
    std::cout << WHITE_B << "6. " << RESET;

    str1 = "Vide";
    str2 = "Vi";
    if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_same_lexico_compare(str1, str2);

    //  7
    std::cout << WHITE_B << "7. " << RESET;

    str1 = "";
    str2 = "🪐";
    if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    is_same_lexico_compare(str1, str2);

    //  8
    std::cout << WHITE_B << "8. " << RESET;

    str2 = "";
    if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    is_same_lexico_compare(str1, str2);

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
        // 1
        std::cout << WHITE_B << "1. " << RESET;
        if (ft::numeric_limits<BoBun>::is_integer)
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        else
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        std::cout << PINK << "Class BoBun" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<BoBun>::is_integer ? "True" : "False") << RESET << std::endl;

        // 2
        std::cout << WHITE_B << "2. " << RESET;
        if (ft::numeric_limits<int>::is_integer)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Int" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<int>::is_integer ? "True" : "False") << RESET << std::endl;

        // 3
        std::cout << WHITE_B << "3. " << RESET;
        if (ft::numeric_limits<const int>::is_integer)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Const Int" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<const int>::is_integer ? "True" : "False") << RESET << std::endl;

        // 4
        std::cout << WHITE_B << "4. " << RESET;
        if (ft::numeric_limits<volatile int>::is_integer)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Volatile Int" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<volatile int>::is_integer ? "True" : "False") << RESET << std::endl;

        // 5
        std::cout << WHITE_B << "5. " << RESET;
        if (ft::numeric_limits<char>::is_integer)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Char" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<char>::is_integer ? "True" : "False") << RESET << std::endl;

        // 6
        std::cout << WHITE_B << "6. " << RESET;
        if (ft::numeric_limits<int*>::is_integer)
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        else
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        std::cout << PINK << "Int*" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<int*>::is_integer ? "True" : "False") << RESET << std::endl;

        // 7
        std::cout << WHITE_B << "7. " << RESET;
        if (ft::numeric_limits<bool>::is_integer)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Bool" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<bool>::is_integer ? "True" : "False") << RESET << std::endl;

        // 8
        std::cout << WHITE_B << "8. " << RESET;
        if (ft::numeric_limits<wchar_t>::is_integer)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Wchar_t" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<wchar_t>::is_integer ? "True" : "False") << RESET << std::endl;

        // 9
        std::cout << WHITE_B << "9. " << RESET;
        if (ft::numeric_limits<short>::is_integer)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Short" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<short>::is_integer ? "True" : "False") << RESET << std::endl;

        // 10
        std::cout << WHITE_B << "10. " << RESET;
        if (ft::numeric_limits<long>::is_integer)
            std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << "[" << "❌" << "]      " << RESET;
        std::cout << PINK << "Long" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<long>::is_integer ? "True" : "False") << RESET << std::endl;

        // 11
        std::cout << WHITE_B << "11. " << RESET;
        if (ft::numeric_limits<long long>::is_integer)
            std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << "[" << "❌" << "]      " << RESET;
        std::cout << PINK << "Long Long" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<long long>::is_integer ? "True" : "False") << RESET << std::endl;

        // 12
        std::cout << WHITE_B << "12. " << RESET;
        if (ft::numeric_limits<float>::is_integer)
    		std::cout << PINK << "[" << "❌" << "]      " << RESET;
        else
            std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
        std::cout << PINK << "Float" << RESET << " is a bon intègre ? " << GREEN << (ft::numeric_limits<float>::is_integer ? "True" : "False") << RESET << std::endl;
    #else
       // 1
        std::cout << WHITE_B << "1. " << RESET;
        if (ft::is_integral<BoBun>::value)
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        else
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        std::cout << PINK << "Class BoBun" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<BoBun>::value ? "True" : "False") << RESET << std::endl;

        // 2
        std::cout << WHITE_B << "2. " << RESET;
        if (ft::is_integral<int>::value)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Int" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<int>::value ? "True" : "False") << RESET << std::endl;

        // 3
        std::cout << WHITE_B << "3. " << RESET;
        if (ft::is_integral<const int>::value)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Const Int" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<const int>::value ? "True" : "False") << RESET << std::endl;

        // 4
        std::cout << WHITE_B << "4. " << RESET;
        if (ft::is_integral<volatile int>::value)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Volatile Int" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<volatile int>::value ? "True" : "False") << RESET << std::endl;

        // 5
        std::cout << WHITE_B << "5. " << RESET;
        if (ft::is_integral<char>::value)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Char" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<char>::value ? "True" : "False") << RESET << std::endl;

        // 6
        std::cout << WHITE_B << "6. " << RESET;
        if (ft::is_integral<int*>::value)
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        else
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        std::cout << PINK << "Int*" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<int*>::value ? "True" : "False") << RESET << std::endl;

        // 7
        std::cout << WHITE_B << "7. " << RESET;
        if (ft::is_integral<bool>::value)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Bool" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<bool>::value ? "True" : "False") << RESET << std::endl;

        // 8
        std::cout << WHITE_B << "8. " << RESET;
        if (ft::is_integral<wchar_t>::value)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Wchar_t" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<wchar_t>::value ? "True" : "False") << RESET << std::endl;

        // 9
        std::cout << WHITE_B << "9. " << RESET;
        if (ft::is_integral<short>::value)
            std::cout << GREEN <<" [" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << " [" << "❌" << "]      " << RESET;
        std::cout << PINK << "Short" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<short>::value ? "True" : "False") << RESET << std::endl;

        // 10
        std::cout << WHITE_B << "10. " << RESET;
        if (ft::is_integral<long>::value)
            std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << "[" << "❌" << "]      " << RESET;
        std::cout << PINK << "Long" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<long>::value? "True" : "False") << RESET << std::endl;

        // 11
        std::cout << WHITE_B << "11. " << RESET;
        if (ft::is_integral<long long>::value)
            std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
        else
    		std::cout << PINK << "[" << "❌" << "]      " << RESET;
        std::cout << PINK << "Long Long" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<long long>::value ? "True" : "False") << RESET << std::endl;

        // 12
        std::cout << WHITE_B << "12. " << RESET;
        if (ft::is_integral<float>::value)
    		std::cout << PINK << "[" << "❌" << "]      " << RESET;
        else
            std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
        std::cout << PINK << "Float" << RESET << " is a bon intègre ? " << GREEN << (ft::is_integral<float>::value ? "True" : "False") << RESET << std::endl;
    #endif
    std::cout << "\n\n";
}

/*********************************************************
 *														 *
 *		P A I R  &  M A K E _ P A I R   				 *
 *														 *
 *********************************************************/

template<class T, class U>
void    print_contenus_of_pair(T first, U second) {

    std::cout << "(" << PINK << first << ", " << second << RESET << ")" << "\t";
}

void    test_lapeyre() {

    //
    //  TEST DE LAPEYRE, IL Y EN A PAS DEUX
    //

    title_of_test("Test de Lapeyre, il y en a pas deux");

    std::pair<int, int> p1(42, -24);
    std::pair<int, int> p2(0, 1000);

    //  CONTENUS
    std::cout << WHITE_B << "CONTENUS.    " << RESET;

    if (p1.first == 42 && p1.second == -24)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p1.first, p1.second);

    if (p2.first == 0 && p2.second == 1000)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p2.first, p2.second);
    std::cout << std::endl;

    //  AFFECTATION
    std::cout << WHITE_B << "AFFECTATION. " << RESET;

    p1 = p2;
    if (p1.first == 0 && p1.second == 1000)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p1.first, p1.second);

    if (p2.first == 0 && p2.second == 1000)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p2.first, p2.second);
    std::cout << std::endl;

    // MAKE_PAIR
    std::cout << WHITE_B << "MAKE_PAIR.   " << RESET;

    std::pair<int, int> p = std::make_pair(42, -24);
    if (p.first == 42 && p.second == -24)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p.first, p.second);

    p = std::make_pair(0, 1000);
    if (p.first == 0 && p.second == 1000)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p.first, p.second);
    std::cout << std::endl << std::endl;

    // OPERATORS
    std::cout << WHITE_B << "OPERATORS.   " << RESET;
    std::cout << std::endl;

    std::pair<int, int> pA(1, 2);
    std::pair<int, int> pB(1, 2);
    std::pair<int, int> pC(2, 3);

    std::cout << WHITE << "         =   " << RESET;
    if (pA == pB)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "        !=   " << RESET;
    if (pA != pC)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "         <   " << RESET;
    if (pA < pC)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    if (pA < pB)
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "        <=   " << RESET;
    if (pA <= pC)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    if (pA <= pB)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "         >   " << RESET;
    if (pC > pA)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    if (pB > pA)
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "        >=   " << RESET;
    if (pC >= pA)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    if (pB >= pA)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;

    std::cout << std::endl << std::endl << std::endl;
}

void    test_manege() {

    title_of_test("Test de Tournez Manege !!!");

    std::pair<std::string, std::string> p1("Ingrid", "Robert");
    std::pair<std::string, std::string> p2("Marie", "Eudes");

    //  CONTENUS
    std::cout << WHITE_B << "CONTENUS.    " << RESET;

    if (p1.first == "Ingrid" && p1.second == "Robert")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p1.first, p1.second);

    if (p2.first == "Marie" && p2.second == "Eudes")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p2.first, p2.second);
    std::cout << std::endl;

    //  AFFECTATION
    std::cout << WHITE_B << "AFFECTATION. " << RESET;

    p1 = p2;
    if (p2.first == "Marie" && p2.second == "Eudes")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p1.first, p1.second);

    if (p2.first == "Marie" && p2.second == "Eudes")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p2.first, p2.second);
    std::cout << std::endl;

    // MAKE_PAIR
    std::cout << WHITE_B << "MAKE_PAIR.   " << RESET;

    std::pair<std::string, std::string> p = std::make_pair("Ingrid", "Robert");
    if (p.first == "Ingrid" && p.second == "Robert")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p.first, p.second);

    p = std::make_pair("Marie", "Eudes");
    if (p.first == "Marie" && p.second == "Eudes")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    print_contenus_of_pair(p.first, p.second);
    std::cout << std::endl << std::endl;

    // OPERATORS
    std::cout << WHITE_B << "OPERATORS.   " << RESET;
    std::cout << std::endl;

    std::pair<std::string, std::string> pA("Ingrid", "Robert");
    std::pair<std::string, std::string> pB("Ingrid", "Robert");
    std::pair<std::string, std::string> pC("Indie", "Robespierre");

    std::cout << WHITE << "         =   " << RESET;
    if (pA == pB)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "        !=   " << RESET;
    if (pA != pC)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "         <   " << RESET;
    if (pA < pC)
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    if (pA < pB)
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "        <=   " << RESET;
    if (pA <= pC)
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    if (pA <= pB)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "         >   " << RESET;
    if (pC > pA)
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    if (pB > pA)
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    std::cout << std::endl;

    std::cout << WHITE << "        >=   " << RESET;
    if (pC >= pA)
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    else
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    if (pB >= pA)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
    std::cout << std::endl << std::endl;
}

void    test_make_pair() {

    title_of_function("Pair & Make_Pair");

    test_lapeyre();
    test_manege();
}

