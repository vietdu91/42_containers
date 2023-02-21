/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:27:32 by emtran            #+#    #+#             */
/*   Updated: 2023/02/16 14:53:31 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.hpp"
#include <cassert>

template <typename T1, typename T2>
void test_default_constructor() {

    ft::map<T1, T2> a;

    std::cout << WHITE << "EMPTY.       " << RESET;
    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl;

    std::cout << WHITE << "INSERT.      " << RESET;

	a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    for (int i = 1; i < 51; i++) {

		if (a.insert(ft::make_pair<T1, T2>(T1(), T2())).second == false)
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
    		std::cout << PINK << "[" << "❌" << "] " << RESET;
		if ((i % 9 == 0))
			std::cout << std::endl << "             ";
	}
	std::cout << std::endl;

    std::cout << WHITE << "SIZE.        " << RESET;
    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl;

	typename ft::map<T1, T2>::iterator it = a.begin();

    std::cout << WHITE << "INSERT.      " << RESET;
	if (a.insert(ft::make_pair<T1, T2>(T1(), T2())).first == it)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;
}

void default_constructor() {

	std::cout << std::endl;
	title_of_test("Decouverte de la carte au tresor [default constructor]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET << std::endl;
    test_default_constructor<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET << std::endl;
    test_default_constructor<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET << std::endl;
    test_default_constructor<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET << std::endl;
    test_default_constructor<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET << std::endl;
    test_default_constructor<int, std::string>();

}

template <typename T1, typename T2>
void test_range_constructor() {

    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    ft::map<T1, T2> b(a.begin(), a.end());

    if (b.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    b.erase(b.begin());

    if (b.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void range_constructor() {

	std::cout << std::endl;

	title_of_test("Construction du navire [range constructor]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_range_constructor<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_range_constructor<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_range_constructor<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_range_constructor<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_range_constructor<int, std::string>();
}

template <typename T1, typename T2>
void test_copy_constructor() {

    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    ft::map<T1, T2> b(a);

    if (b.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    b.erase(b.begin());

    if (b.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void copy_constructor() {

	std::cout << std::endl;

	title_of_test("Copie de la carte au tresor en cas de perte [copy constructor]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_copy_constructor<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_copy_constructor<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_copy_constructor<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_copy_constructor<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_copy_constructor<int, std::string>();
}

template <typename T1, typename T2>
void test_assignement_operator() {

    ft::map<T1, T2> a;
    ft::map<T1, T2> b;

    a = b;

    if (a.empty())
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;
    if (b.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    b = a;

    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    if (b.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.erase(a.begin());

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (b.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void assignement_operator() {

	std::cout << std::endl;

	title_of_test("Assignation des membres d'equipage [assignment operator]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_assignement_operator<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_assignement_operator<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_assignement_operator<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_assignement_operator<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_assignement_operator<int, std::string>();
}

void test_begin_end_practical() {

    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    a.insert(ft::make_pair<char, int>('b', 5));

    if ((*(a.begin())).first == 'a')
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if ((*(++a.begin())).first == 'b')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(--a.end())).first == 'b')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl << std::endl;
}

template <typename T1, typename T2>
void test_begin_end() {

    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    size_t count = 0;
    for (typename ft::map<T1, T2>::iterator it = a.begin(); it != a.end(); it++)
    {
		if ((*(it)).first == T1())
	        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
		else
	    	std::cout << PINK << "[" << "❌" << "] " << RESET;

		if ((*(it)).second == T2())
	        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
	    	std::cout << PINK << "[" << "❌" << "] " << RESET;

        count++;
    }

	if (count == a.size() && count == 1)
	    std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void begin_end() {

	std::cout << std::endl;

	title_of_test("Tracage du trajet vers le tresor [begin end]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_begin_end_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_begin_end<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_begin_end<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_begin_end<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_begin_end<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_begin_end<int, std::string>();
}

void test_rbegin_rend_practical() {

    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    a.insert(ft::make_pair<char, int>('b', 5));

    if ((*(a.rbegin())).first == 'b')
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if ((*(++a.rbegin())).first == 'a')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(--a.rend())).first == 'a')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_rbegin_rend() {

    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    size_t count = 0;
    for (typename ft::map<T1, T2>::reverse_iterator it = a.rbegin(); it != a.rend(); it++)
    {
		if ((*(it)).first == T1())
	        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
		else
	    	std::cout << PINK << "[" << "❌" << "] " << RESET;

		if ((*(it)).second == T2())
	        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
	    	std::cout << PINK << "[" << "❌" << "] " << RESET;
        count++;
    }
    assert(count == a.size() && count == 1);

	std::cout << std::endl;
}

void rbegin_rend() {

	std::cout << std::endl;

	title_of_test("Calcul du trajet retour vers la maison [rbgin rend]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_rbegin_rend_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_rbegin_rend<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_rbegin_rend<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_rbegin_rend<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_rbegin_rend<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_rbegin_rend<int, std::string>();
}

template <typename T1, typename T2>
void test_empty() {

    ft::map<T1, T2> a;

    if (a.empty())
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    if (!a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.erase(a.begin());

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void empty() {

	std::cout << std::endl;

	title_of_test("Verification des rations s'ils ne sont pas vides [empty]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_empty<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_empty<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_empty<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_empty<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_empty<int, std::string>();
}

template <typename T1, typename T2>
void test_size() {

    ft::map<T1, T2> a;

    if (a.size() == 0)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

	for (int i = 0; i < 50; i++)
		a.insert(ft::make_pair<T1, T2>(T1(), T2()));

	if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.erase(a.begin());
    if (a.size() == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void size() {

	std::cout << std::endl;

	title_of_test("Calcul des rations [size]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_size<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_size<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_size<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_size<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_size<int, std::string>();
}

void max_size() {

	std::cout << std::endl;

    ft::map<char, int> a;

	title_of_test("Stock max des rations dans le navire [max_size]");

    std::cout << WHITE_B << "1. " << RESET;
    if (a.max_size() == 230584300921369395)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void test_operator_access_practical() {

    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    a.insert(ft::make_pair<char, int>('b', 5));
    a.insert(ft::make_pair<char, int>('c', 5));
    a.insert(ft::make_pair<char, int>('d', 5));

    if (a['a'] == 5)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if (a['b'] == 5)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a['c'] == 5)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a['d'] == 5)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a['e'] = 10;

    if (a['e'] == 10)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.size() == 5)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a['f'];

    if (a.size() == 6)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a['f'];

    if (a.size() == 6)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a['a'] = 10;

    if (a['a'] == 10)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.insert(ft::make_pair<char, int>('a', 5));

    if (a['a'] == 10)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_operator_access() {

    ft::map<T1, T2> a;

    for (int i = 0; i < 50; i++)
        a[T1()] = T2();

    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if ((*(a.begin())).first == T1())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	if ((*(a.begin())).second == a[T1()])
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	if (a[T1()] == T2())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void operator_access() {

	std::cout << std::endl;
	title_of_test("Acces de l'equipage dans le navire [operator access]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_operator_access_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_operator_access<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_operator_access<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_operator_access<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_operator_access<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_operator_access<int, std::string>();
}

void test_insert_single_practical() {

    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    a.insert(ft::make_pair<char, int>('a', 5));
    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.insert(ft::make_pair<char, int>('a', 999));
    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.insert(ft::make_pair<char, int>('b', 0));
    if (a.size() == 2)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void test_insert_range_practical() {

    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    a.insert(ft::make_pair<char, int>('b', 6));
    a.insert(ft::make_pair<char, int>('c', 5));
    a.insert(ft::make_pair<char, int>('d', 6));

    if (a.size() == 4)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    ft::map<char, int> b;

    b.insert(a.begin(), a.end());

    if (b.size() == 4)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    b.insert(a.begin(), a.end());

    if (b.size() == 4)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void test_insert_hint_practical() {

    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 5));

    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 6));
    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.insert(a.begin(), ft::make_pair<char, int>('b', 6));
    if (a.size() == 2)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void test_insert_practical() {

	std::cout << std::endl;
    std::cout << WHITE << "SINGLE.              " << RESET;
    test_insert_single_practical();
    std::cout << WHITE << "RANGE.               " << RESET;
    test_insert_range_practical();
    std::cout << WHITE << "HINT.                " << RESET;
    test_insert_hint_practical();
}

template <typename T1, typename T2>
void test_insert() {

    ft::map<T1, T2> a;
    ft::map<T1, T2> empty;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    ft::map<T1, T2> b;

    b.insert(empty.begin(), empty.end());
    if (b.empty() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    b.insert(a.begin(), a.end());
    if (b.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    b.insert(a.begin(), a.end());
    if (b.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void insert() {

	std::cout << std::endl;
	title_of_test("A l'abordage ! [insert practical]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_insert_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_insert<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_insert<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_insert<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_insert<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_insert<int, std::string>();
}

void test_erase_practical() {

    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 1));
    a.insert(a.begin(), ft::make_pair<char, int>('b', 2));
    a.insert(a.begin(), ft::make_pair<char, int>('c', 3));
    a.insert(a.begin(), ft::make_pair<char, int>('d', 4));

    if ((*(a.begin())).first == 'a')
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if (a.size() == 4)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.erase(a.begin());

    if ((*(a.begin())).first == 'b')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(a.begin())).second == 2)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.erase(a.begin());

    if ((*(a.begin())).first == 'c')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(a.begin())).second == 3)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.erase(a.begin());

    if ((*(a.begin())).first == 'd')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(a.begin())).second == 4)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void test_erase_key_practical() {

    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 1));
    a.insert(a.begin(), ft::make_pair<char, int>('b', 2));
    a.insert(a.begin(), ft::make_pair<char, int>('c', 3));
    a.insert(a.begin(), ft::make_pair<char, int>('d', 4));

    if (a.erase('a') == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if (a.erase('a') == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.erase('b') == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.erase('b') == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.erase('c') == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.erase('c') == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.erase('d') == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.erase('d') == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.erase('z') == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_erase_key() {

    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    if (a.erase(T1()) == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if (a.empty())
        std::cout << GREEN <<"[" << "✅"	<< "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.erase(T1()) == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void test_erase_range_practical() {

    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 1));
    a.insert(a.begin(), ft::make_pair<char, int>('b', 2));
    a.insert(a.begin(), ft::make_pair<char, int>('c', 3));
    a.insert(a.begin(), ft::make_pair<char, int>('d', 4));

    a.erase(a.begin(), ++a.begin());

    if ((*(a.begin())).first == 'b')
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if ((*(a.begin())).second == 2)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.erase(a.begin(), a.end());

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_erase_range() {

    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    a.erase(a.begin(), a.end());

    if (a.empty())
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    a.erase(a.begin(), a.end());

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void erase()
{
	std::cout << std::endl;
	title_of_test("Une baleine arrive ! [erase]");

	std::cout << std::endl;
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "Practical         " << RESET;
    test_erase_practical();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "Range             " << RESET;
    test_erase_range_practical();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "Key               " << RESET;
    test_erase_key_practical();

	std::cout << std::endl;
	title_of_test("1 mort a bord... [erase_key]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_erase_key<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_erase_key<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_erase_key<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_erase_key<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_erase_key<int, std::string>();

	std::cout << std::endl;
	title_of_test("Une brochette de 10 morts a bord... [erase_range]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_erase_range<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_erase_range<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_erase_range<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_erase_range<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_erase_range<int, std::string>();
}

void test_swap_practical() {

    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 1));
    a.insert(a.begin(), ft::make_pair<char, int>('b', 2));
    a.insert(a.begin(), ft::make_pair<char, int>('c', 3));
    a.insert(a.begin(), ft::make_pair<char, int>('d', 4));

    ft::map<char, int> b;

    a.swap(b);

    if (b.size() == 4)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(b.begin())).first == 'a')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(++b.begin())).first == 'b')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(--b.end())).first == 'd')
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_swap() {

    ft::map<T1, T2> a;
    ft::map<T1, T2> b;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if ((*(a.begin())).first == T1())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(a.begin())).second == T2())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(--a.end())).first == T1())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(--a.end())).second == T2())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (b.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.swap(b);

    if (b.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(b.begin())).first == T1())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(b.begin())).second == T2())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(--b.end())).first == T1())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if ((*(--b.end())).second == T2())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void swap() {

	std::cout << std::endl;
	title_of_test("A la conquete de l'ile au tresor ! [swap]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_swap_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_swap<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_swap<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_swap<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_swap<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_swap<int, std::string>();
}

void test_clear_practical()
{
    ft::map<char, int> a;

    for (int i = 0; i < 50; i++)
        a.insert(ft::make_pair<char, int>(i, i));

    if (a.size() == 50)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    a.clear();

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_clear()
{
    ft::map<T1, T2> a;

    a[T1()] = T2();

    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    a.clear();

    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a[T1()];

    if (a.size() == 1)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    a.clear();
    if (a.empty())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void clear()
{
	std::cout << std::endl;
	title_of_test("Creusage du trou... [clear]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_clear_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_clear<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_clear<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_clear<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_clear<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_clear<int, std::string>();
}

template <typename T1, typename T2>
void test_find() {

    ft::map<T1, T2> a;
    const ft::map<T1, T2> b;

    if (a.find(T1()) == a.end())
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if (b.find(T1()) == b.end())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a[T1()];

    if (a.size() == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (a.find(T1()) == a.begin())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
    if (a.find(T1()) == --a.end())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (b.size() == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    if (b.find(T1()) == b.begin())
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void find() {

	std::cout << std::endl;
	title_of_test("Tresor TROUVE !!!!!! [find]");

    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_find<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_find<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_find<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_find<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_find<int, std::string>();
}

void test_count_practical()
{
    ft::map<char, int> 	a;
	bool				trap = 0;

    for (int i = 1; i < 51; i++)
        a.insert(ft::make_pair<char, int>(i, i));

    for (int i = 1; i < 51; i++) {

		if (a.count(i) == 1 && trap == 0)
		{
			trap = 1;
        	std::cout << GREEN <<" [" << "✅" << "] " << RESET;
		}
		else if (a.count(i) == 1 && trap == 1)
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
    		std::cout << PINK << "[" << "❌" << "] " << RESET;
		if ((i % 9 == 0))
			std::cout << std::endl << "                      ";
	}
	std::cout << std::endl << "                      ";
	if (a.count(51) == 0)
    	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << "                      ";

    a.clear();

    for (int i = 1; i < 51; i++) {

		if (a.count(i) == 0)
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
    		std::cout << PINK << "[" << "❌" << "] " << RESET;
		if ((i % 9 == 0))
			std::cout << std::endl << "                      ";
	}

	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_count()
{
    ft::map<T1, T2> a;

    if (a.count(T1()) == 0)
        std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << " [" << "❌" << "] " << RESET;

    if (a.count(T1()) == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a[T1()];

    if (a.count(T1()) == 1)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

    a.erase(a.begin());

    if (a.count(T1()) == 0)
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
    	std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;

}

void count() {

	std::cout << std::endl;
	title_of_test("Comptage des pieces !!!!!! [count]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_count_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_count<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_count<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_count<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_count<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_count<int, std::string>();
}

void test_lower_bound_practical() {

    ft::map<char, int> a;
    std::map<char, int> std_a;
	bool trap1 = 0;
	bool trap2 = 0;

    for (int i = 0; i < 50; i++) {

        a.insert(ft::make_pair<char, int>(i, i));
        std_a.insert(std::make_pair(i, i));

		if ((*(a.lower_bound(i))).first == i && trap1 == 0)
		{
			trap1 = 1;
        	std::cout << GREEN <<" [" << "✅" << "] " << RESET;
		}
		else if ((*(a.lower_bound(i))).first == i && trap1 == 1)
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
    		std::cout << PINK << "[" << "❌" << "] " << RESET;
		if ((i % 5 == 0))
			std::cout << std::endl << "                      ";

		if ((*(std_a.lower_bound(i))).first == i && trap2 == 0)
		{
			trap2 = 1;
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		}
		else if ((*(a.lower_bound(i))).first == i && trap1 == 1)
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
    		std::cout << PINK << "[" << "❌" << "] " << RESET;
		if ((i % 9 == 0))
			std::cout << std::endl << "                      ";
    }
    a.clear();
    std_a.clear();

	if (a.lower_bound(char()) == a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (std_a.lower_bound(char()) == std_a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

    a['a'] = 20;
    a['b'] = 40;
    a['c'] = 60;
    a['d'] = 80;
    a['e'] = 100;
    a['g'] = 120;

    std_a['a'] = 20;
    std_a['b'] = 40;
    std_a['c'] = 60;
    std_a['d'] = 80;
    std_a['e'] = 100;
    std_a['g'] = 120;

	if (std_a.lower_bound('b') == ++std_a.begin())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (std_a.lower_bound('f') == --std_a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(std_a.lower_bound('f'))).first == 'g')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(std_a.lower_bound('f'))).second == 120)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

	if (a.lower_bound('b') == ++a.begin())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (a.lower_bound('f') == --a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(a.lower_bound('f'))).first == 'g')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(a.lower_bound('f'))).second == 120)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

    const ft::map<char, int> b = a;

	if (b.lower_bound('b') == ++b.begin())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (b.lower_bound('f') == --b.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(b.lower_bound('f'))).first == 'g')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(b.lower_bound('f'))).second == 120)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_lower_bound()
{
    ft::map<T1, T2> a;
    std::map<T1, T2> std_a;

	if (a.lower_bound(T1()) == a.end())
 		std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << " [" << "❌" << "] " << RESET;
	if (std_a.lower_bound(T1()) == std_a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

    a[T1()];
    std_a[T1()];

	if (a.lower_bound(T1()) == a.begin())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(a.lower_bound(T1()))).first == T1())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(a.lower_bound(T1()))).second == T2())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

	if (std_a.lower_bound(T1()) == std_a.begin())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(std_a.lower_bound(T1()))).first == T1())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(std_a.lower_bound(T1()))).second == T2())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

    const ft::map<T1, T2> b(a);

	if (b.lower_bound(T1()) == b.begin())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(b.lower_bound(T1()))).first == T1())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(b.lower_bound(T1()))).second == T2())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void lower_bound() {

	std::cout << std::endl;
	title_of_test("Distribution de quelques ecus pour l'equipage [lower_bound]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_lower_bound_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_lower_bound<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_lower_bound<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_lower_bound<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_lower_bound<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_lower_bound<int, std::string>();
}

void test_upper_bound_practical() {

    ft::map<char, int> a;
    std::map<char, int> std_a;
	bool trap1 = 0;
	bool trap2 = 0;

    for (int i = 0; i < 50; i++) {

        a.insert(ft::make_pair<char, int>(i, i));
        std_a.insert(std::make_pair(i, i));

		if (a.upper_bound(i) == a.end() && trap1 == 0)
		{
			trap1 = 1;
        	std::cout << GREEN <<" [" << "✅" << "] " << RESET;
		}
		else if (a.upper_bound(i) == a.end() && trap1 == 1)
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
    		std::cout << PINK << "[" << "❌" << "] " << RESET;
		if ((i % 5 == 0))
			std::cout << std::endl << "                      ";

		if (std_a.upper_bound(i) == std_a.end() && trap2 == 0)
		{
			trap2 = 1;
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		}
		else if (std_a.upper_bound(i) == std_a.end() && trap1 == 1)
        	std::cout << GREEN <<"[" << "✅" << "] " << RESET;
		else
    		std::cout << PINK << "[" << "❌" << "] " << RESET;
		if ((i % 9 == 0))
			std::cout << std::endl << "                      ";
    }
    a.clear();
    std_a.clear();

	if (a.upper_bound(char()) == a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (std_a.upper_bound(char()) == std_a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

    a['a'] = 20;
    a['b'] = 40;
    a['c'] = 60;
    a['d'] = 80;
    a['e'] = 100;
    a['g'] = 120;

    std_a['a'] = 20;
    std_a['b'] = 40;
    std_a['c'] = 60;
    std_a['d'] = 80;
    std_a['e'] = 100;
    std_a['g'] = 120;

	if ((*(std_a.upper_bound('a'))).first == 'b')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(std_a.upper_bound('a'))).second == 40)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(std_a.upper_bound('f'))).first == 'g')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(std_a.upper_bound('f'))).second == 120)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (std_a.upper_bound('g') == std_a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

	if ((*(a.upper_bound('a'))).first == 'b')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(a.upper_bound('a'))).second == 40)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(a.upper_bound('f'))).first == 'g')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(a.upper_bound('f'))).second == 120)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (a.upper_bound('g') == a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

    const ft::map<char, int> b = a;

	if ((*(b.upper_bound('a'))).first == 'b')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(b.upper_bound('a'))).second == 40)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(b.upper_bound('f'))).first == 'g')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if ((*(b.upper_bound('f'))).second == 120)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (b.upper_bound('g') == b.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

template <typename T1, typename T2>
void test_upper_bound()
{
    ft::map<T1, T2> a;
    std::map<T1, T2> std_a;

	if (a.upper_bound(T1()) == a.end())
 		std::cout << GREEN <<" [" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << " [" << "❌" << "] " << RESET;
	if (std_a.upper_bound(T1()) == std_a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

    a[T1()];
    std_a[T1()];

	if (a.upper_bound(T1()) == a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (std_a.upper_bound(T1()) == std_a.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

    const ft::map<T1, T2> b(a);

	if (b.upper_bound(T1()) == b.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl;
}

void upper_bound()
{
	std::cout << std::endl;
	title_of_test("Le CAPITAINE VEUT PRENDRE TOUTE LA TUNE [upper_bound]");

    std::cout << WHITE_B << "0. " << RESET << BLUE_B << "Mise en place     " << RESET;
    test_upper_bound_practical();
    std::cout << WHITE_B << "1. " << RESET << BLUE_B << "<char, int>       " << RESET;
    test_upper_bound<char, int>();
    std::cout << WHITE_B << "2. " << RESET << BLUE_B << "<int, int>        " << RESET;
    test_upper_bound<int, int>();
    std::cout << WHITE_B << "3. " << RESET << BLUE_B << "<float, char>     " << RESET;
    test_upper_bound<float, char>();
    std::cout << WHITE_B << "4. " << RESET << BLUE_B << "<char *, int>     " << RESET;
    test_upper_bound<char *, int>();
    std::cout << WHITE_B << "5. " << RESET << BLUE_B << "<int, std::string>" << RESET;
    test_upper_bound<int, std::string>();
}

void equal_range() {

	std::cout << std::endl;
	title_of_test("REVOLUTION ! Capitaine au bucher et le tresor pour l'humanite !!! [equal]");

    ft::map<char, int> mymap;

    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;

    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
    ret = mymap.equal_range('b');

	std::cout << WHITE_B << "1. " << RESET;
	if (ret.first->first == 'b')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (ret.first->second == 20)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (ret.second->first == 'c')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (ret.second->second == 30)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl;

    ret = mymap.equal_range('c');

	std::cout << WHITE_B << "2. " << RESET;
	if (ret.first->first == 'c')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (ret.first->second == 30)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (ret.second == mymap.end())
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl;

    mymap['e'] = 50;

    ret = mymap.equal_range('d');

	std::cout << WHITE_B << "3. " << RESET;
	if (ret.first->first == 'e')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (ret.first->second == 50)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (ret.second->first == 'e')
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (ret.second->second == 50)
 		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
 		std::cout << PINK << "[" << "❌" << "] " << RESET;

	std::cout << std::endl << std::endl << std::endl;
}

void	test_de_la_carte_du_tresor() {

    title_of_function("Test de la carte au tresor");

    default_constructor();
    range_constructor();
    copy_constructor();
    assignement_operator();
    begin_end();
    rbegin_rend();
    empty();
    size();
    max_size();
    operator_access();
    insert();
    erase();
    swap();
    clear();
    find();
    count();
    lower_bound();
    upper_bound();
    equal_range();
}

void	test_de_l_humanite() {

    title_of_function("Test genealogique de l'humanite");

	ft::map<std::string, int> test_insert;

	test_insert.insert(ft::make_pair(std::string("twohundredfiftyseven"),257));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftysix"),556));
	test_insert.insert(ft::make_pair(std::string("onehundredtwenty"),120));
	test_insert.insert(ft::make_pair(std::string("ninehundredfive"),905));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightynine"),689));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtyone"),431));
	test_insert.insert(ft::make_pair(std::string("thirtyeight"),38));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtythree"),333));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventyseven"),477));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftythree"),553));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentysix"),126));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightyone"),581));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtyone"),131));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtyeight"),138));
	test_insert.insert(ft::make_pair(std::string("threehundredeight"),308));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixteen"),916));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtyone"),261));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtyone"),961));
	test_insert.insert(ft::make_pair(std::string("sixhundredfour"),604));
	test_insert.insert(ft::make_pair(std::string("onehundredninetysix"),196));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventyfive"),575));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtythree"),763));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventyfour"),474));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftyseven"),157));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftythree"),453));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortyone"),941));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetyeight"),798));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtyfour"),834));
	test_insert.insert(ft::make_pair(std::string("sixtyfour"),64));
	test_insert.insert(ft::make_pair(std::string("eighthundrednineteen"),819));
	test_insert.insert(ft::make_pair(std::string("threehundredeightyfive"),385));
	test_insert.insert(ft::make_pair(std::string("twohundredeightytwo"),282));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightyone"),681));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftyone"),151));
	test_insert.insert(ft::make_pair(std::string("threehundredeighty"),380));
	test_insert.insert(ft::make_pair(std::string("twohundredseventeen"),217));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtynine"),769));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightyseven"),587));
	test_insert.insert(ft::make_pair(std::string("twohundredninetythree"),293));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftysix"),156));
	test_insert.insert(ft::make_pair(std::string("sixhundrednine"),609));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftythree"),853));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortyseven"),447));
	test_insert.insert(ft::make_pair(std::string("onehundredeleven"),111));
	test_insert.insert(ft::make_pair(std::string("threehundredsixty"),360));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftysix"),356));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwo"),402));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtyfive"),535));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtytwo"),662));
	test_insert.insert(ft::make_pair(std::string("eleven"),11));
	test_insert.insert(ft::make_pair(std::string("threehundrednineteen"),319));
	test_insert.insert(ft::make_pair(std::string("twohundredfive"),205));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtyone"),331));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftyeight"),658));
	test_insert.insert(ft::make_pair(std::string("twohundredfiftysix"),256));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtytwo"),862));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtynine"),869));
	test_insert.insert(ft::make_pair(std::string("twentyfour"),24));
	test_insert.insert(ft::make_pair(std::string("threehundredone"),301));
	test_insert.insert(ft::make_pair(std::string("onehundredfifty"),150));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetyeight"),698));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtysix"),836));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtyseven"),167));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtyfour"),534));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtyfive"),465));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentyone"),821));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortyfive"),845));
	test_insert.insert(ft::make_pair(std::string("fortysix"),46));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftynine"),359));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtynine"),839));
	test_insert.insert(ft::make_pair(std::string("fivehundredeleven"),511));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftysix"),656));
	test_insert.insert(ft::make_pair(std::string("sevenhundred"),700));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentytwo"),422));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftyone"),751));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventyfour"),774));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortyfive"),545));
	test_insert.insert(ft::make_pair(std::string("eighthundredeighty"),880));
	test_insert.insert(ft::make_pair(std::string("threehundredtwo"),302));
	test_insert.insert(ft::make_pair(std::string("nine"),9));
	test_insert.insert(ft::make_pair(std::string("threehundredfortyfive"),345));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetyeight"),598));
	test_insert.insert(ft::make_pair(std::string("threehundredthree"),303));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftyseven"),757));
	test_insert.insert(ft::make_pair(std::string("twohundredten"),210));
	test_insert.insert(ft::make_pair(std::string("threehundredninetyeight"),398));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtytwo"),232));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetyfour"),994));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftytwo"),752));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwelve"),812));
	test_insert.insert(ft::make_pair(std::string("fivehundredeighty"),580));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtyfour"),864));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventynine"),779));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtyeight"),238));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortythree"),743));
	test_insert.insert(ft::make_pair(std::string("onehundredeightytwo"),182));
	test_insert.insert(ft::make_pair(std::string("sixtytwo"),62));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtyfive"),665));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightyeight"),788));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentynine"),429));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetythree"),693));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightytwo"),582));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentyseven"),727));
	test_insert.insert(ft::make_pair(std::string("onehundredseventyfive"),175));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftyone"),951));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetyseven"),997));
	test_insert.insert(ft::make_pair(std::string("twohundredseventynine"),279));
	test_insert.insert(ft::make_pair(std::string("fiftyone"),51));
	test_insert.insert(ft::make_pair(std::string("fivehundredthree"),503));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtytwo"),932));
	test_insert.insert(ft::make_pair(std::string("twohundredfiftyfour"),254));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentyfour"),924));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightytwo"),782));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentyseven"),527));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftyeight"),558));
	test_insert.insert(ft::make_pair(std::string("threehundredeightytwo"),382));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentyfour"),824));
	test_insert.insert(ft::make_pair(std::string("twohundredthree"),203));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortyeight"),948));
	test_insert.insert(ft::make_pair(std::string("onehundredthirteen"),113));
	test_insert.insert(ft::make_pair(std::string("seventyseven"),77));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwo"),702));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetyeight"),498));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightysix"),786));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightyfive"),585));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortyeight"),848));
	test_insert.insert(ft::make_pair(std::string("twohundredeightynine"),289));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixteen"),716));
	test_insert.insert(ft::make_pair(std::string("fourhundredeighty"),480));
	test_insert.insert(ft::make_pair(std::string("onehundredeightyfive"),185));
	test_insert.insert(ft::make_pair(std::string("twohundrednine"),209));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtyeight"),568));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwenty"),620));
	test_insert.insert(ft::make_pair(std::string("threehundredseventyeight"),378));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftyfour"),454));
	test_insert.insert(ft::make_pair(std::string("sevenhundrednine"),709));
	test_insert.insert(ft::make_pair(std::string("eighthundredfifty"),850));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfifty"),750));
	test_insert.insert(ft::make_pair(std::string("eightysix"),86));
	test_insert.insert(ft::make_pair(std::string("sixhundredninety"),690));
	test_insert.insert(ft::make_pair(std::string("sixhundredten"),610));
	test_insert.insert(ft::make_pair(std::string("threehundredninetyfour"),394));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventysix"),576));
	test_insert.insert(ft::make_pair(std::string("fortytwo"),42));
	test_insert.insert(ft::make_pair(std::string("ninetyfour"),94));
	test_insert.insert(ft::make_pair(std::string("thirtytwo"),32));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftyseven"),657));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentyeight"),728));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentyfive"),725));
	test_insert.insert(ft::make_pair(std::string("threehundredeightyone"),381));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtyone"),831));
	test_insert.insert(ft::make_pair(std::string("threehundredfifteen"),315));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtyeight"),838));
	test_insert.insert(ft::make_pair(std::string("fourhundrednine"),409));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtynine"),639));
	test_insert.insert(ft::make_pair(std::string("twohundredseven"),207));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentyseven"),927));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentyfive"),825));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftytwo"),652));
	test_insert.insert(ft::make_pair(std::string("twentyone"),21));
	test_insert.insert(ft::make_pair(std::string("twohundredseventyone"),271));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortyeight"),448));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtyeight"),168));
	test_insert.insert(ft::make_pair(std::string("fortyeight"),48));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortythree"),843));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventytwo"),872));
	test_insert.insert(ft::make_pair(std::string("onehundredseven"),107));
	test_insert.insert(ft::make_pair(std::string("twohundredeightyseven"),287));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftysix"),956));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixty"),460));
	test_insert.insert(ft::make_pair(std::string("thirtythree"),33));
	test_insert.insert(ft::make_pair(std::string("fivehundrednineteen"),519));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentyfive"),525));
	test_insert.insert(ft::make_pair(std::string("threehundredninetyfive"),395));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtyone"),531));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtyseven"),837));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightyfour"),684));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightythree"),483));
	test_insert.insert(ft::make_pair(std::string("threehundredninetytwo"),392));
	test_insert.insert(ft::make_pair(std::string("onehundredeightyeight"),188));
	test_insert.insert(ft::make_pair(std::string("sixtyfive"),65));
	test_insert.insert(ft::make_pair(std::string("twohundredseventyseven"),277));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentynine"),129));
	test_insert.insert(ft::make_pair(std::string("ninehundredfifteen"),915));
	test_insert.insert(ft::make_pair(std::string("twohundredfortyone"),241));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightyfour"),584));
	test_insert.insert(ft::make_pair(std::string("eightyseven"),87));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtytwo"),732));
	test_insert.insert(ft::make_pair(std::string("onehundredsix"),106));
	test_insert.insert(ft::make_pair(std::string("sixhundredeighteen"),618));
	test_insert.insert(ft::make_pair(std::string("ninehundredeight"),908));
	test_insert.insert(ft::make_pair(std::string("threehundredninetyone"),391));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentyseven"),127));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetyfour"),594));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtyeight"),738));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtyseven"),967));
	test_insert.insert(ft::make_pair(std::string("sixhundred"),600));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentynine"),929));
	test_insert.insert(ft::make_pair(std::string("seventythree"),73));
	test_insert.insert(ft::make_pair(std::string("twentyseven"),27));
	test_insert.insert(ft::make_pair(std::string("eightytwo"),82));
	test_insert.insert(ft::make_pair(std::string("fiftysix"),56));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortynine"),549));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightytwo"),982));
	test_insert.insert(ft::make_pair(std::string("onehundredseventysix"),176));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortynine"),849));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtysix"),436));
	test_insert.insert(ft::make_pair(std::string("seventy"),70));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtyseven"),867));
	test_insert.insert(ft::make_pair(std::string("sixteen"),16));
	test_insert.insert(ft::make_pair(std::string("one"),1));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortythree"),543));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetytwo"),592));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventyfour"),874));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtysix"),336));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentyfive"),625));
	test_insert.insert(ft::make_pair(std::string("seventytwo"),72));
	test_insert.insert(ft::make_pair(std::string("twohundredfortytwo"),242));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortynine"),449));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtytwo"),432));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfourteen"),714));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightyseven"),787));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtyone"),561));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtyeight"),438));
	test_insert.insert(ft::make_pair(std::string("onehundredeightynine"),189));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtyfive"),365));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftyone"),551));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtyeight"),468));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixteen"),616));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftyone"),351));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightyeight"),888));
	test_insert.insert(ft::make_pair(std::string("twohundredeightyfour"),284));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftyseven"),957));
	test_insert.insert(ft::make_pair(std::string("three"),3));
	test_insert.insert(ft::make_pair(std::string("fivehundredfifty"),550));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtythree"),633));
	test_insert.insert(ft::make_pair(std::string("onehundredfortythree"),143));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtyfour"),564));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtynine"),239));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixty"),860));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtyfour"),434));
	test_insert.insert(ft::make_pair(std::string("seventyone"),71));
	test_insert.insert(ft::make_pair(std::string("twohundredeightyone"),281));
	test_insert.insert(ft::make_pair(std::string("onehundredfortyseven"),147));
	test_insert.insert(ft::make_pair(std::string("threehundredseventythree"),373));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortyone"),841));
	test_insert.insert(ft::make_pair(std::string("threehundredeightyfour"),384));
	test_insert.insert(ft::make_pair(std::string("ninehundredone"),901));
	test_insert.insert(ft::make_pair(std::string("fourhundrednineteen"),419));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetyfour"),894));
	test_insert.insert(ft::make_pair(std::string("threehundredsix"),306));
	test_insert.insert(ft::make_pair(std::string("twohundredfortyseven"),247));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightyfive"),685));
	test_insert.insert(ft::make_pair(std::string("threehundredninetysix"),396));
	test_insert.insert(ft::make_pair(std::string("fiftyfour"),54));
	test_insert.insert(ft::make_pair(std::string("ninehundredeleven"),911));
	test_insert.insert(ft::make_pair(std::string("ninehundrednineteen"),919));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftyfive"),655));
	test_insert.insert(ft::make_pair(std::string("onehundredninetytwo"),192));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtysix"),266));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventeen"),617));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtynine"),969));
	test_insert.insert(ft::make_pair(std::string("onehundredninetyseven"),197));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtynine"),469));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtyfive"),135));
	test_insert.insert(ft::make_pair(std::string("onehundredeightythree"),183));
	test_insert.insert(ft::make_pair(std::string("ninehundred"),900));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtyone"),731));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtysix"),866));
	test_insert.insert(ft::make_pair(std::string("threehundredninety"),390));
	test_insert.insert(ft::make_pair(std::string("onehundredfortyone"),141));
	test_insert.insert(ft::make_pair(std::string("eighthundredfive"),805));
	test_insert.insert(ft::make_pair(std::string("twohundredfortyfour"),244));
	test_insert.insert(ft::make_pair(std::string("twohundredfortysix"),246));
	test_insert.insert(ft::make_pair(std::string("threehundredeightyeight"),388));
	test_insert.insert(ft::make_pair(std::string("onehundredfifteen"),115));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftynine"),859));
	test_insert.insert(ft::make_pair(std::string("seventysix"),76));
	test_insert.insert(ft::make_pair(std::string("fourhundred"),400));
	test_insert.insert(ft::make_pair(std::string("twentysix"),26));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentyeight"),628));
	test_insert.insert(ft::make_pair(std::string("fivehundredfive"),505));
	test_insert.insert(ft::make_pair(std::string("ninetytwo"),92));
	test_insert.insert(ft::make_pair(std::string("onehundredfour"),104));
	test_insert.insert(ft::make_pair(std::string("sixty"),60));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventynine"),979));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtyeight"),338));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventyfive"),775));
	test_insert.insert(ft::make_pair(std::string("twohundredfifty"),250));
	test_insert.insert(ft::make_pair(std::string("eightythree"),83));
	test_insert.insert(ft::make_pair(std::string("sevenhundredten"),710));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtyfour"),264));
	test_insert.insert(ft::make_pair(std::string("onehundredninetyfour"),194));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortythree"),643));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightythree"),883));
	test_insert.insert(ft::make_pair(std::string("sixtyseven"),67));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortynine"),649));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentyseven"),827));
	test_insert.insert(ft::make_pair(std::string("fourhundredninety"),490));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftyfour"),954));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtysix"),466));
	test_insert.insert(ft::make_pair(std::string("ninehundredfifty"),950));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtytwo"),362));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventy"),470));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventythree"),473));
	test_insert.insert(ft::make_pair(std::string("eighthundredfifteen"),815));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtyseven"),367));
	test_insert.insert(ft::make_pair(std::string("five"),5));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetytwo"),492));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentyfive"),425));
	test_insert.insert(ft::make_pair(std::string("ninehundredeighty"),980));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtyfour"),934));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftysix"),756));
	test_insert.insert(ft::make_pair(std::string("sixhundredeight"),608));
	test_insert.insert(ft::make_pair(std::string("onehundredeightyone"),181));
	test_insert.insert(ft::make_pair(std::string("eighthundred"),800));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortysix"),546));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftyeight"),958));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftysix"),456));
	test_insert.insert(ft::make_pair(std::string("eighty"),80));
	test_insert.insert(ft::make_pair(std::string("sixhundredeighty"),680));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtyfour"),634));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtyone"),861));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentyone"),421));
	test_insert.insert(ft::make_pair(std::string("sixtyeight"),68));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetytwo"),692));
	test_insert.insert(ft::make_pair(std::string("fourhundredfive"),405));
	test_insert.insert(ft::make_pair(std::string("onehundrednineteen"),119));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirty"),530));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventyeight"),878));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortyfive"),945));
	test_insert.insert(ft::make_pair(std::string("onehundredfortyfive"),145));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventythree"),873));
	test_insert.insert(ft::make_pair(std::string("eighthundrednine"),809));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtyfour"),234));
	test_insert.insert(ft::make_pair(std::string("threehundredseventynine"),379));
	test_insert.insert(ft::make_pair(std::string("ninehundredfourteen"),914));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwenty"),420));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventeen"),417));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentyfour"),224));
	test_insert.insert(ft::make_pair(std::string("fiftyfive"),55));
	test_insert.insert(ft::make_pair(std::string("fivehundred"),500));
	test_insert.insert(ft::make_pair(std::string("threehundredfive"),305));
	test_insert.insert(ft::make_pair(std::string("ninetynine"),99));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortynine"),949));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftyfive"),855));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeight"),708));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventysix"),876));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightysix"),586));
	test_insert.insert(ft::make_pair(std::string("fourhundredfifteen"),415));
	test_insert.insert(ft::make_pair(std::string("ninehundrednine"),909));
	test_insert.insert(ft::make_pair(std::string("thirtyone"),31));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentyeight"),428));
	test_insert.insert(ft::make_pair(std::string("fivehundredfifteen"),515));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventytwo"),472));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtythree"),963));
	test_insert.insert(ft::make_pair(std::string("fivehundrednine"),509));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightynine"),589));
	test_insert.insert(ft::make_pair(std::string("sixhundredfive"),605));
	test_insert.insert(ft::make_pair(std::string("seven"),7));
	test_insert.insert(ft::make_pair(std::string("twohundredforty"),240));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtyeight"),668));
	test_insert.insert(ft::make_pair(std::string("onehundredtwo"),102));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetyfour"),494));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentyfive"),125));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightytwo"),482));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetyfive"),795));
	test_insert.insert(ft::make_pair(std::string("onehundredninetyone"),191));
	test_insert.insert(ft::make_pair(std::string("twohundredninetyone"),291));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtyfour"),134));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortysix"),446));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightyone"),881));
	test_insert.insert(ft::make_pair(std::string("eighthundredsix"),806));
	test_insert.insert(ft::make_pair(std::string("thirtysix"),36));
	test_insert.insert(ft::make_pair(std::string("threehundredseventysix"),376));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfive"),705));
	test_insert.insert(ft::make_pair(std::string("sixhundredthree"),603));
	test_insert.insert(ft::make_pair(std::string("sixhundredfifteen"),615));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtyeight"),968));
	test_insert.insert(ft::make_pair(std::string("threehundredseventeen"),317));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortyseven"),947));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwo"),602));
	test_insert.insert(ft::make_pair(std::string("fourhundredthree"),403));
	test_insert.insert(ft::make_pair(std::string("twohundredtwenty"),220));
	test_insert.insert(ft::make_pair(std::string("threehundredfortyone"),341));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentyone"),521));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentynine"),629));
	test_insert.insert(ft::make_pair(std::string("onehundredthirty"),130));
	test_insert.insert(ft::make_pair(std::string("threehundredeightyseven"),387));
	test_insert.insert(ft::make_pair(std::string("eighthundredeleven"),811));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetyfive"),495));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftyfive"),755));
	test_insert.insert(ft::make_pair(std::string("threehundredfifty"),350));
	test_insert.insert(ft::make_pair(std::string("fiftytwo"),52));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetyfour"),794));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetynine"),799));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwo"),902));
	test_insert.insert(ft::make_pair(std::string("onehundredeighteen"),118));
	test_insert.insert(ft::make_pair(std::string("onehundredseventythree"),173));
	test_insert.insert(ft::make_pair(std::string("threehundredfortyfour"),344));
	test_insert.insert(ft::make_pair(std::string("threehundred"),300));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirty"),430));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtyseven"),137));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentythree"),123));
	test_insert.insert(ft::make_pair(std::string("fortyfour"),44));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortyfour"),944));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventyone"),771));
	test_insert.insert(ft::make_pair(std::string("six"),6));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventyeight"),478));
	test_insert.insert(ft::make_pair(std::string("eightyeight"),88));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftyone"),851));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightyeight"),588));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtythree"),263));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetytwo"),792));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentytwo"),222));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetynine"),499));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetyone"),591));
	test_insert.insert(ft::make_pair(std::string("fivehundredseven"),507));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirty"),830));
	test_insert.insert(ft::make_pair(std::string("eighthundredninety"),890));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtynine"),739));
	test_insert.insert(ft::make_pair(std::string("onehundredseventy"),170));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwelve"),712));
	test_insert.insert(ft::make_pair(std::string("twohundredeightyeight"),288));
	test_insert.insert(ft::make_pair(std::string("onehundredfortysix"),146));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventyfive"),475));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftyfive"),955));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortyone"),641));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentynine"),529));
	test_insert.insert(ft::make_pair(std::string("threehundredtwenty"),320));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetythree"),993));
	test_insert.insert(ft::make_pair(std::string("twohundredfiftyeight"),258));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightynine"),889));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtythree"),533));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortysix"),746));
	test_insert.insert(ft::make_pair(std::string("twelve"),12));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortyone"),441));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtyone"),931));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventy"),570));
	test_insert.insert(ft::make_pair(std::string("onehundredsixteen"),116));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsix"),706));
	test_insert.insert(ft::make_pair(std::string("onehundredseventynine"),179));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetythree"),593));
	test_insert.insert(ft::make_pair(std::string("seventeen"),17));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftynine"),459));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirteen"),613));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftyfive"),155));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetysix"),596));
	test_insert.insert(ft::make_pair(std::string("ninetysix"),96));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftyfive"),355));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentysix"),726));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtysix"),166));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtyone"),761));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentysix"),226));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightyeight"),988));
	test_insert.insert(ft::make_pair(std::string("twohundredfiftynine"),259));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightyseven"),687));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentythree"),223));
	test_insert.insert(ft::make_pair(std::string("eighthundredseven"),807));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtyfive"),335));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortyseven"),747));
	test_insert.insert(ft::make_pair(std::string("fiftyseven"),57));
	test_insert.insert(ft::make_pair(std::string("eightyfour"),84));
	test_insert.insert(ft::make_pair(std::string("fivehundredfour"),504));
	test_insert.insert(ft::make_pair(std::string("fortythree"),43));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftyfive"),455));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentythree"),823));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtyfour"),764));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentynine"),729));
	test_insert.insert(ft::make_pair(std::string("onehundredfortytwo"),142));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtysix"),136));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixty"),660));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwelve"),412));
	test_insert.insert(ft::make_pair(std::string("twohundredninetytwo"),292));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtysix"),766));
	test_insert.insert(ft::make_pair(std::string("threehundredseventy"),370));
	test_insert.insert(ft::make_pair(std::string("onehundrednine"),109));
	test_insert.insert(ft::make_pair(std::string("eightyone"),81));
	test_insert.insert(ft::make_pair(std::string("twohundredninetyfour"),294));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventy"),970));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventysix"),676));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirteen"),913));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortytwo"),542));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightysix"),886));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtyone"),461));
	test_insert.insert(ft::make_pair(std::string("onehundredseventyfour"),174));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtythree"),463));
	test_insert.insert(ft::make_pair(std::string("twohundredthirty"),230));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirty"),930));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentyone"),721));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentyone"),221));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentytwo"),322));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtyseven"),667));
	test_insert.insert(ft::make_pair(std::string("fourhundredforty"),440));
	test_insert.insert(ft::make_pair(std::string("thirtynine"),39));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetysix"),896));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtytwo"),462));
	test_insert.insert(ft::make_pair(std::string("eighthundredthree"),803));
	test_insert.insert(ft::make_pair(std::string("twohundredfortynine"),249));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightytwo"),682));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentynine"),329));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentysix"),526));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftyfour"),754));
	test_insert.insert(ft::make_pair(std::string("twohundredfiftyfive"),255));
	test_insert.insert(ft::make_pair(std::string("fortyfive"),45));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtyfive"),865));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeleven"),711));
	test_insert.insert(ft::make_pair(std::string("sixhundredseven"),607));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetyfive"),995));
	test_insert.insert(ft::make_pair(std::string("twohundredfiftythree"),253));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftyeight"),858));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentyeight"),528));
	test_insert.insert(ft::make_pair(std::string("threehundredseventyfive"),375));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftythree"),953));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetytwo"),992));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventy"),770));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortyeight"),548));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtynine"),669));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtysix"),666));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtyfour"),364));
	test_insert.insert(ft::make_pair(std::string("onehundredfortynine"),149));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightyfour"),484));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtyseven"),437));
	test_insert.insert(ft::make_pair(std::string("onehundredeightyfour"),184));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetyone"),491));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetyfour"),694));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortytwo"),642));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtynine"),939));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtythree"),133));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventytwo"),772));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftynine"),659));
	test_insert.insert(ft::make_pair(std::string("fiftynine"),59));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwenty"),720));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftynine"),759));
	test_insert.insert(ft::make_pair(std::string("fifty"),50));
	test_insert.insert(ft::make_pair(std::string("fortyone"),41));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftyseven"),857));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftytwo"),152));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftynine"),159));
	test_insert.insert(ft::make_pair(std::string("onehundredseventyseven"),177));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightyseven"),887));
	test_insert.insert(ft::make_pair(std::string("threehundrednine"),309));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetynine"),999));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentytwo"),922));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtynine"),169));
	test_insert.insert(ft::make_pair(std::string("twohundredninetynine"),299));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortyfive"),445));
	test_insert.insert(ft::make_pair(std::string("threehundredfortyeight"),348));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtythree"),563));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetynine"),599));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtynine"),339));
	test_insert.insert(ft::make_pair(std::string("fivehundredeighteen"),518));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightysix"),486));
	test_insert.insert(ft::make_pair(std::string("sixhundredforty"),640));
	test_insert.insert(ft::make_pair(std::string("threehundredseventyfour"),374));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortythree"),943));
	test_insert.insert(ft::make_pair(std::string("zero"),0));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventynine"),479));
	test_insert.insert(ft::make_pair(std::string("forty"),40));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtythree"),833));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtytwo"),262));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventysix"),476));
	test_insert.insert(ft::make_pair(std::string("thirtyfour"),34));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtytwo"),562));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtyfive"),565));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventyfive"),975));
	test_insert.insert(ft::make_pair(std::string("threehundredeighteen"),318));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtysix"),936));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventyseven"),877));
	test_insert.insert(ft::make_pair(std::string("sixhundredeleven"),611));
	test_insert.insert(ft::make_pair(std::string("fourhundredeleven"),411));
	test_insert.insert(ft::make_pair(std::string("threehundredeightynine"),389));
	test_insert.insert(ft::make_pair(std::string("sevenhundredone"),701));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentytwo"),822));
	test_insert.insert(ft::make_pair(std::string("seventynine"),79));
	test_insert.insert(ft::make_pair(std::string("ninetyfive"),95));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftyseven"),357));
	test_insert.insert(ft::make_pair(std::string("ninetyone"),91));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentythree"),423));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentythree"),523));
	test_insert.insert(ft::make_pair(std::string("fourhundredeight"),408));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftysix"),856));
	test_insert.insert(ft::make_pair(std::string("twohundredtwo"),202));
	test_insert.insert(ft::make_pair(std::string("fivehundredten"),510));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseven"),707));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtyseven"),537));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentythree"),723));
	test_insert.insert(ft::make_pair(std::string("twohundredeight"),208));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftyfive"),555));
	test_insert.insert(ft::make_pair(std::string("threehundredfortynine"),349));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtytwo"),332));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentyone"),121));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftyseven"),557));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwenty"),920));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetythree"),793));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtyfour"),664));
	test_insert.insert(ft::make_pair(std::string("sixhundredsix"),606));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirteen"),713));
	test_insert.insert(ft::make_pair(std::string("threehundredfortysix"),346));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightytwo"),882));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightyfive"),885));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightysix"),986));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortyseven"),847));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventysix"),776));
	test_insert.insert(ft::make_pair(std::string("ninety"),90));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventythree"),673));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightyfive"),485));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwenty"),520));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtyeight"),768));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortyone"),541));
	test_insert.insert(ft::make_pair(std::string("threehundredeleven"),311));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtynine"),569));
	test_insert.insert(ft::make_pair(std::string("sixtynine"),69));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventyone"),671));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtyseven"),237));
	test_insert.insert(ft::make_pair(std::string("fourhundredeighteen"),418));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortyseven"),647));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentyeight"),928));
	test_insert.insert(ft::make_pair(std::string("threehundredfour"),304));
	test_insert.insert(ft::make_pair(std::string("fifteen"),15));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventyeight"),678));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtynine"),439));
	test_insert.insert(ft::make_pair(std::string("onehundredone"),101));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortyfive"),745));
	test_insert.insert(ft::make_pair(std::string("sixtythree"),63));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtyeight"),538));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventysix"),976));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetythree"),493));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetyone"),691));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirteen"),513));
	test_insert.insert(ft::make_pair(std::string("threehundredfortyseven"),347));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortysix"),846));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentysix"),826));
	test_insert.insert(ft::make_pair(std::string("twohundredseventyfour"),274));
	test_insert.insert(ft::make_pair(std::string("threehundredseven"),307));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetyeight"),898));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftytwo"),952));
	test_insert.insert(ft::make_pair(std::string("thirty"),30));
	test_insert.insert(ft::make_pair(std::string("twohundredseventysix"),276));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftyeight"),758));
	test_insert.insert(ft::make_pair(std::string("fourhundredseven"),407));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentyfive"),325));
	test_insert.insert(ft::make_pair(std::string("twentyeight"),28));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtytwo"),132));
	test_insert.insert(ft::make_pair(std::string("onehundredforty"),140));
	test_insert.insert(ft::make_pair(std::string("twohundredsix"),206));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirty"),630));
	test_insert.insert(ft::make_pair(std::string("fivehundredeight"),508));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventytwo"),672));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtysix"),736));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixty"),960));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtytwo"),632));
	test_insert.insert(ft::make_pair(std::string("twohundredseventytwo"),272));
	test_insert.insert(ft::make_pair(std::string("fivehundredninety"),590));
	test_insert.insert(ft::make_pair(std::string("onehundredseventyone"),171));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftythree"),353));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventytwo"),972));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtyseven"),737));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirteen"),413));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentyeight"),828));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtytwo"),962));
	test_insert.insert(ft::make_pair(std::string("fiftythree"),53));
	test_insert.insert(ft::make_pair(std::string("twohundredeleven"),211));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtysix"),566));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtysix"),536));
	test_insert.insert(ft::make_pair(std::string("onehundredsixty"),160));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventyseven"),777));
	test_insert.insert(ft::make_pair(std::string("thirtyfive"),35));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortysix"),946));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftytwo"),552));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtythree"),733));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtyone"),661));
	test_insert.insert(ft::make_pair(std::string("two"),2));
	test_insert.insert(ft::make_pair(std::string("sevenhundredforty"),740));
	test_insert.insert(ft::make_pair(std::string("twohundredninety"),290));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventyeight"),978));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventyfive"),875));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventytwo"),572));
	test_insert.insert(ft::make_pair(std::string("twohundredfour"),204));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventyseven"),677));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortyfour"),544));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentyone"),921));
	test_insert.insert(ft::make_pair(std::string("fiftyeight"),58));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventyeight"),578));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwelve"),912));
	test_insert.insert(ft::make_pair(std::string("ninehundredfortytwo"),942));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventyone"),571));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtyeight"),868));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftyone"),651));
	test_insert.insert(ft::make_pair(std::string("fourhundredfourteen"),414));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortynine"),749));
	test_insert.insert(ft::make_pair(std::string("threehundredninetyseven"),397));
	test_insert.insert(ft::make_pair(std::string("fortyseven"),47));
	test_insert.insert(ft::make_pair(std::string("twohundredsixteen"),216));
	test_insert.insert(ft::make_pair(std::string("onehundredeightysix"),186));
	test_insert.insert(ft::make_pair(std::string("sevenhundrednineteen"),719));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortyfour"),644));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortythree"),443));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentynine"),229));
	test_insert.insert(ft::make_pair(std::string("fourhundredfifty"),450));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortyeight"),648));
	test_insert.insert(ft::make_pair(std::string("eighteen"),18));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwenty"),820));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtythree"),363));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentyseven"),327));
	test_insert.insert(ft::make_pair(std::string("threehundredthirteen"),313));
	test_insert.insert(ft::make_pair(std::string("onehundredthirtynine"),139));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightythree"),683));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtyseven"),467));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftyfour"),154));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentyseven"),627));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtythree"),163));
	test_insert.insert(ft::make_pair(std::string("onehundredseventytwo"),172));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventynine"),679));
	test_insert.insert(ft::make_pair(std::string("twentythree"),23));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtyone"),231));
	test_insert.insert(ft::make_pair(std::string("twohundredfiftytwo"),252));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtyseven"),767));
	test_insert.insert(ft::make_pair(std::string("ninetyseven"),97));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventyfour"),574));
	test_insert.insert(ft::make_pair(std::string("twohundredseventythree"),273));
	test_insert.insert(ft::make_pair(std::string("fortynine"),49));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftythree"),653));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeighty"),780));
	test_insert.insert(ft::make_pair(std::string("twentytwo"),22));
	test_insert.insert(ft::make_pair(std::string("ninehundredfiftynine"),959));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtyone"),161));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetysix"),796));
	test_insert.insert(ft::make_pair(std::string("twohundredfourteen"),214));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixtythree"),863));
	test_insert.insert(ft::make_pair(std::string("threehundredeightysix"),386));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeighteen"),718));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwelve"),512));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixty"),560));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtyfive"),635));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentytwo"),722));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwo"),502));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentyeight"),328));
	test_insert.insert(ft::make_pair(std::string("threehundredninetythree"),393));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtynine"),269));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentyfour"),124));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtyfive"),165));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftyseven"),457));
	test_insert.insert(ft::make_pair(std::string("onehundredseventeen"),117));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwo"),802));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentyfive"),225));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfifteen"),715));
	test_insert.insert(ft::make_pair(std::string("fourhundredone"),401));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightyone"),981));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentythree"),323));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtyfour"),734));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtyfive"),935));
	test_insert.insert(ft::make_pair(std::string("eighthundredtwentynine"),829));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfiftythree"),753));
	test_insert.insert(ft::make_pair(std::string("threehundredfourteen"),314));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightyeight"),488));
	test_insert.insert(ft::make_pair(std::string("ninehundredfour"),904));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventeen"),817));
	test_insert.insert(ft::make_pair(std::string("threehundredforty"),340));
	test_insert.insert(ft::make_pair(std::string("fourhundredsix"),406));
	test_insert.insert(ft::make_pair(std::string("fivehundredforty"),540));
	test_insert.insert(ft::make_pair(std::string("twentynine"),29));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventeen"),917));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetyone"),791));
	test_insert.insert(ft::make_pair(std::string("sixhundredfourteen"),614));
	test_insert.insert(ft::make_pair(std::string("eighthundredeight"),808));
	test_insert.insert(ft::make_pair(std::string("onehundredfive"),105));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortytwo"),442));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixteen"),516));
	test_insert.insert(ft::make_pair(std::string("onehundredtwelve"),112));
	test_insert.insert(ft::make_pair(std::string("onehundredten"),110));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftyeight"),358));
	test_insert.insert(ft::make_pair(std::string("ninehundredseven"),907));
	test_insert.insert(ft::make_pair(std::string("threehundredfortythree"),343));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftytwo"),352));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightythree"),983));
	test_insert.insert(ft::make_pair(std::string("sixtyone"),61));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventy"),870));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightynine"),789));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtyeight"),268));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentysix"),926));
	test_insert.insert(ft::make_pair(std::string("twohundredeightysix"),286));
	test_insert.insert(ft::make_pair(std::string("threehundredsixteen"),316));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventyfour"),974));
	test_insert.insert(ft::make_pair(std::string("eighthundredeighteen"),818));
	test_insert.insert(ft::make_pair(std::string("twohundredone"),201));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortyfive"),645));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtyfour"),164));
	test_insert.insert(ft::make_pair(std::string("eighthundredten"),810));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetysix"),996));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftytwo"),452));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetyone"),991));
	test_insert.insert(ft::make_pair(std::string("fivehundredeightythree"),583));
	test_insert.insert(ft::make_pair(std::string("threehundredseventyone"),371));
	test_insert.insert(ft::make_pair(std::string("fivehundredone"),501));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtyfive"),965));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventyseven"),977));
	test_insert.insert(ft::make_pair(std::string("twohundredeightythree"),283));
	test_insert.insert(ft::make_pair(std::string("onehundredninetynine"),199));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightyfour"),984));
	test_insert.insert(ft::make_pair(std::string("onehundredninetyeight"),198));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtyseven"),337));
	test_insert.insert(ft::make_pair(std::string("twohundredthirteen"),213));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetyfive"),895));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetysix"),496));
	test_insert.insert(ft::make_pair(std::string("onehundredthree"),103));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentyfour"),424));
	test_insert.insert(ft::make_pair(std::string("threehundredninetynine"),399));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtythree"),233));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetynine"),899));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentytwo"),122));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetynine"),699));
	test_insert.insert(ft::make_pair(std::string("onehundredeightyseven"),187));
	test_insert.insert(ft::make_pair(std::string("twohundredfifteen"),215));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentyeight"),228));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetyseven"),597));
	test_insert.insert(ft::make_pair(std::string("seventyfive"),75));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixteen"),416));
	test_insert.insert(ft::make_pair(std::string("threehundredten"),310));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtyeight"),368));
	test_insert.insert(ft::make_pair(std::string("onehundredtwentyeight"),128));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetythree"),893));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightynine"),989));
	test_insert.insert(ft::make_pair(std::string("threehundredfortytwo"),342));
	test_insert.insert(ft::make_pair(std::string("twohundredninetysix"),296));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetyseven"),697));
	test_insert.insert(ft::make_pair(std::string("eighthundredsixteen"),816));
	test_insert.insert(ft::make_pair(std::string("sixhundredsixtythree"),663));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwelve"),612));
	test_insert.insert(ft::make_pair(std::string("threehundredthirty"),330));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtyeight"),638));
	test_insert.insert(ft::make_pair(std::string("ten"),10));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtyeight"),938));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentyfive"),925));
	test_insert.insert(ft::make_pair(std::string("sevenhundredtwentyfour"),724));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentythree"),623));
	test_insert.insert(ft::make_pair(std::string("onehundredsixtytwo"),162));
	test_insert.insert(ft::make_pair(std::string("ninehundredsix"),906));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtyfive"),435));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetytwo"),892));
	test_insert.insert(ft::make_pair(std::string("onehundredninety"),190));
	test_insert.insert(ft::make_pair(std::string("ninehundredninety"),990));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentysix"),426));
	test_insert.insert(ft::make_pair(std::string("threehundredfiftyfour"),354));
	test_insert.insert(ft::make_pair(std::string("onehundredeight"),108));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventyeight"),778));
	test_insert.insert(ft::make_pair(std::string("sixhundredfortysix"),646));
	test_insert.insert(ft::make_pair(std::string("twohundredninetyfive"),295));
	test_insert.insert(ft::make_pair(std::string("threehundredeightythree"),383));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtyfive"),835));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirtyfive"),735));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtyfive"),235));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtysix"),366));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentyfour"),524));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtyone"),631));
	test_insert.insert(ft::make_pair(std::string("twohundredtwelve"),212));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtyseven"),937));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightyone"),481));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightynine"),489));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentysix"),326));
	test_insert.insert(ft::make_pair(std::string("ninehundredninetyeight"),998));
	test_insert.insert(ft::make_pair(std::string("fivehundredsixtyseven"),567));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentyfour"),624));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventynine"),879));
	test_insert.insert(ft::make_pair(std::string("fourhundredninetyseven"),497));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetyone"),891));
	test_insert.insert(ft::make_pair(std::string("ninehundredthree"),903));
	test_insert.insert(ft::make_pair(std::string("fivehundredtwentytwo"),522));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtysix"),636));
	test_insert.insert(ft::make_pair(std::string("eighthundredninetyseven"),897));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtynine"),369));
	test_insert.insert(ft::make_pair(std::string("eighthundredseventyone"),871));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortytwo"),742));
	test_insert.insert(ft::make_pair(std::string("thirteen"),13));
	test_insert.insert(ft::make_pair(std::string("nineteen"),19));
	test_insert.insert(ft::make_pair(std::string("fourhundredthirtythree"),433));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftyfour"),554));
	test_insert.insert(ft::make_pair(std::string("fourhundredfour"),404));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightyfive"),985));
	test_insert.insert(ft::make_pair(std::string("twohundredfortyfive"),245));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortytwo"),842));
	test_insert.insert(ft::make_pair(std::string("sixhundredfiftyfour"),654));
	test_insert.insert(ft::make_pair(std::string("twohundredseventy"),270));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightyone"),781));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightythree"),783));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtynine"),539));
	test_insert.insert(ft::make_pair(std::string("onehundredninetyfive"),195));
	test_insert.insert(ft::make_pair(std::string("threehundredseventytwo"),372));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortyone"),741));
	test_insert.insert(ft::make_pair(std::string("four"),4));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightyeight"),688));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventeen"),517));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventythree"),573));
	test_insert.insert(ft::make_pair(std::string("twohundredeighty"),280));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortyfour"),744));
	test_insert.insert(ft::make_pair(std::string("thirtyseven"),37));
	test_insert.insert(ft::make_pair(std::string("seventyeight"),78));
	test_insert.insert(ft::make_pair(std::string("threehundredtwelve"),312));
	test_insert.insert(ft::make_pair(std::string("twohundred"),200));
	test_insert.insert(ft::make_pair(std::string("onehundred"),100));
	test_insert.insert(ft::make_pair(std::string("onehundredfortyfour"),144));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtysix"),966));
	test_insert.insert(ft::make_pair(std::string("fourhundredten"),410));
	test_insert.insert(ft::make_pair(std::string("fivehundredthirtytwo"),532));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirteen"),813));
	test_insert.insert(ft::make_pair(std::string("onehundredseventyeight"),178));
	test_insert.insert(ft::make_pair(std::string("eighthundredone"),801));
	test_insert.insert(ft::make_pair(std::string("threehundredthirtyfour"),334));
	test_insert.insert(ft::make_pair(std::string("twohundredseventyfive"),275));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventythree"),773));
	test_insert.insert(ft::make_pair(std::string("fourhundredseventyone"),471));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightyfour"),784));
	test_insert.insert(ft::make_pair(std::string("eighthundredfour"),804));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftyfour"),854));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthree"),703));
	test_insert.insert(ft::make_pair(std::string("twentyfive"),25));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentyone"),321));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfortyeight"),748));
	test_insert.insert(ft::make_pair(std::string("twenty"),20));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventy"),670));
	test_insert.insert(ft::make_pair(std::string("eighthundredfortyfour"),844));
	test_insert.insert(ft::make_pair(std::string("twohundredfiftyone"),251));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtyseven"),267));
	test_insert.insert(ft::make_pair(std::string("twohundredninetyseven"),297));
	test_insert.insert(ft::make_pair(std::string("twohundredninetyeight"),298));
	test_insert.insert(ft::make_pair(std::string("twohundredsixtyfive"),265));
	test_insert.insert(ft::make_pair(std::string("twohundrednineteen"),219));
	test_insert.insert(ft::make_pair(std::string("twohundredtwentyseven"),227));
	test_insert.insert(ft::make_pair(std::string("onehundredfortyeight"),148));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventyfour"),674));
	test_insert.insert(ft::make_pair(std::string("sevenhundredfour"),704));
	test_insert.insert(ft::make_pair(std::string("twohundredeightyfive"),285));
	test_insert.insert(ft::make_pair(std::string("eightynine"),89));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentysix"),626));
	test_insert.insert(ft::make_pair(std::string("ninehundredforty"),940));
	test_insert.insert(ft::make_pair(std::string("sixhundredfifty"),650));
	test_insert.insert(ft::make_pair(std::string("fivehundredninetyfive"),595));
	test_insert.insert(ft::make_pair(std::string("eight"),8));
	test_insert.insert(ft::make_pair(std::string("fourhundredsixtyfour"),464));
	test_insert.insert(ft::make_pair(std::string("ninehundredeightyseven"),987));
	test_insert.insert(ft::make_pair(std::string("fivehundredfortyseven"),547));
	test_insert.insert(ft::make_pair(std::string("sixhundrednineteen"),619));
	test_insert.insert(ft::make_pair(std::string("twohundredthirtysix"),236));
	test_insert.insert(ft::make_pair(std::string("eighthundredthirtytwo"),832));
	test_insert.insert(ft::make_pair(std::string("sevenhundredeightyfive"),785));
	test_insert.insert(ft::make_pair(std::string("fourhundredfortyfour"),444));
	test_insert.insert(ft::make_pair(std::string("eightyfive"),85));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninety"),790));
	test_insert.insert(ft::make_pair(std::string("eighthundredforty"),840));
	test_insert.insert(ft::make_pair(std::string("twohundredeighteen"),218));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftyeight"),458));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftythree"),153));
	test_insert.insert(ft::make_pair(std::string("ninetyeight"),98));
	test_insert.insert(ft::make_pair(std::string("threehundredseventyseven"),377));
	test_insert.insert(ft::make_pair(std::string("sixtysix"),66));
	test_insert.insert(ft::make_pair(std::string("sixhundredthirtyseven"),637));
	test_insert.insert(ft::make_pair(std::string("fourhundredeightyseven"),487));
	test_insert.insert(ft::make_pair(std::string("sixhundredseventyfive"),675));
	test_insert.insert(ft::make_pair(std::string("fourhundredfiftyone"),451));
	test_insert.insert(ft::make_pair(std::string("ninehundredtwentythree"),923));
	test_insert.insert(ft::make_pair(std::string("twohundredfortythree"),243));
	test_insert.insert(ft::make_pair(std::string("sevenhundredseventeen"),717));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixty"),760));
	test_insert.insert(ft::make_pair(std::string("ninetythree"),93));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetyfive"),695));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtyfive"),765));
	test_insert.insert(ft::make_pair(std::string("threehundredsixtyone"),361));
	test_insert.insert(ft::make_pair(std::string("twohundredseventyeight"),278));
	test_insert.insert(ft::make_pair(std::string("twohundredfortyeight"),248));
	test_insert.insert(ft::make_pair(std::string("onehundredninetythree"),193));
	test_insert.insert(ft::make_pair(std::string("fivehundredfourteen"),514));
	test_insert.insert(ft::make_pair(std::string("eighthundredfiftytwo"),852));
	test_insert.insert(ft::make_pair(std::string("onehundredfiftyeight"),158));
	test_insert.insert(ft::make_pair(std::string("ninehundredeighteen"),918));
	test_insert.insert(ft::make_pair(std::string("fourhundredtwentyseven"),427));
	test_insert.insert(ft::make_pair(std::string("eighthundredeightyfour"),884));
	test_insert.insert(ft::make_pair(std::string("sixhundredninetysix"),696));
	test_insert.insert(ft::make_pair(std::string("onehundredfourteen"),114));
	test_insert.insert(ft::make_pair(std::string("sevenhundredninetyseven"),797));
	test_insert.insert(ft::make_pair(std::string("twohundredsixty"),260));
	test_insert.insert(ft::make_pair(std::string("ninehundredsixtyfour"),964));
	test_insert.insert(ft::make_pair(std::string("fourteen"),14));
	test_insert.insert(ft::make_pair(std::string("fivehundredsix"),506));
	test_insert.insert(ft::make_pair(std::string("sixhundredone"),601));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentytwo"),622));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventynine"),579));
	test_insert.insert(ft::make_pair(std::string("ninehundredten"),910));
	test_insert.insert(ft::make_pair(std::string("sixhundredeightysix"),686));
	test_insert.insert(ft::make_pair(std::string("seventyfour"),74));
	test_insert.insert(ft::make_pair(std::string("fivehundredseventyseven"),577));
	test_insert.insert(ft::make_pair(std::string("onehundredeighty"),180));
	test_insert.insert(ft::make_pair(std::string("threehundredtwentyfour"),324));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventythree"),973));
	test_insert.insert(ft::make_pair(std::string("ninehundredseventyone"),971));
	test_insert.insert(ft::make_pair(std::string("eighthundredfourteen"),814));
	test_insert.insert(ft::make_pair(std::string("sevenhundredsixtytwo"),762));
	test_insert.insert(ft::make_pair(std::string("sixhundredtwentyone"),621));
	test_insert.insert(ft::make_pair(std::string("ninehundredthirtythree"),933));
	test_insert.insert(ft::make_pair(std::string("sevenhundredthirty"),730));
	test_insert.insert(ft::make_pair(std::string("fivehundredfiftynine"),559));

    title_of_test("Genese de l'humanite");

    std::cout << WHITE_B << "SIZE.        " << RESET;
	if (test_insert.size() == 1000)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "MAX_SIZE.    " << RESET;
	if (test_insert.max_size() == 128102389400760775)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "BEGIN.       " << RESET;
	if (test_insert.begin()->first == "eight")
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (test_insert.begin()->second == 8)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "RBEGIN.      " << RESET;
	if (test_insert.rbegin()->first == "zero")
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (test_insert.rbegin()->second == 0)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "COUNT.       " << RESET;
	if (test_insert.count("sixteen"))
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (!test_insert.count("onemillion"))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "BOUND.       " << RESET;
	std::cout << std::endl;
	std::cout << WHITE << "     Upper   " << RESET;
	if (test_insert.lower_bound("sixteen")->first == "sixteen")
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl;
	std::cout << WHITE << "     Lower   " << RESET;
	if (test_insert.upper_bound("sixteen")->first == "sixty")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "FIND.        " << RESET;
	if (test_insert.find("sixteen")->first == "sixteen")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Destruction anthropocenique de l'humanite");

	ft::map<std::string, int>::iterator erase_iterator = test_insert.begin();
	for (; erase_iterator != test_insert.end();){
		ft::map<std::string, int>::iterator tmp = erase_iterator;
		erase_iterator++;
		if (tmp->second % 2 != 0){
			test_insert.erase(tmp);
		}
	}

    std::cout << WHITE_B << "SIZE.        " << RESET;
	if (test_insert.size() == 500)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "MAX_SIZE.    " << RESET;
	if (test_insert.max_size() == 128102389400760775)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "BEGIN.       " << RESET;
	if (test_insert.begin()->first == "eight")
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (test_insert.begin()->second == 8)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "RBEGIN.      " << RESET;
	if (test_insert.rbegin()->first == "zero")
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (test_insert.rbegin()->second == 0)
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "COUNT.       " << RESET;
	if (test_insert.count("sixteen"))
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (!test_insert.count("onemillion"))
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "BOUND.       " << RESET;
	std::cout << std::endl;
	std::cout << WHITE << "     Upper   " << RESET;
	if (test_insert.lower_bound("sixteen")->first == "sixteen")
        std::cout << GREEN <<"[" << "✅" << "] " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl;
	std::cout << WHITE << "     Lower   " << RESET;
	if (test_insert.upper_bound("sixteen")->first == "sixty")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
    else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl;

    std::cout << WHITE_B << "FIND.        " << RESET;
	if (test_insert.find("sixteen")->first == "sixteen")
        std::cout << GREEN <<"[" << "✅" << "]      " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "]      " << RESET;
	std::cout << std::endl << std::endl;
}

void	test_map() {

	test_de_la_carte_du_tresor();
	test_de_l_humanite();
}
