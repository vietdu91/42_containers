/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:48:56 by emtran            #+#    #+#             */
/*   Updated: 2023/01/30 18:37:39 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.hpp"

int main(int argc, char** argv)
{
	//std::cout << "C KI ??? C'EST : " << _NAMESPACE << std::endl;
	intro_std_functions();
	test_equal();
	test_lexicographical_compare();
	test_is_integral();
	test_make_pair();
	test_enable_if();
	test_vector();

	std::cout << GREEN_B << "TEST MAP" << RESET << std::endl;

	ft::map<std::string, int> test;
	// lib_used::map<int, std::string> test;

	for (int i = 1; i < argc - 1;){
		test[argv[i]] = atoi(argv[i+1]);
		// test[atoi(argv[i+1])] = argv[i];
		i += 2;
	}


	// lib_used::map<int,std::string>::iterator it = test.begin();
	ft::map<std::string, int>::iterator it = test.begin();
	for (; it != test.end(); it++){
		std::cout << it->first << "|" << it->second << std::endl;
	}

	// lib_used::map<int,std::string>::reverse_iterator it2 = test.rbegin();
	ft::map<std::string, int>::reverse_iterator it2 = test.rbegin();
	for (; it2 != test.rend(); ++it2){
		std::cout << it2->first << "|" << it2->second << std::endl;
	}

	return (1);
}
