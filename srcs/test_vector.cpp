/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:59:09 by emtran            #+#    #+#             */
/*   Updated: 2023/02/02 13:06:09 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.hpp"

void	compare_and_print(size_t p1, size_t p2){
	if (p1 == p2)
		std::cout << GREEN <<"[OK]" << RESET;
	else
		std::cout << PINK << "[KO]" << RESET;
}

template <class InputIterator1, class InputIterator2>
void	compare_vector_and_print(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
	if (ft::equal(first1, last1, first2))
		std::cout << GREEN <<"[OK]" << RESET;
	else
		std::cout << PINK << "[KO]" << RESET;
}

int test_vector(){
	ft::vector<int> ft1;
	ft::vector<int> ft2;
	ft::vector<int> ft3;

	std::vector<int> std1;
	std::vector<int> std2;
	std::vector<int> std3;
	for (int i = 0 ; i < 100 ; i++){
		ft1.push_back(i);
		ft2.push_back(i);
		ft3.push_back(i * 2);
		std1.push_back(i);
		std2.push_back(i);
		std3.push_back(i * 2);
	}

	std::cout << YELLOW<<"compare size of vectors" <<RESET << std::endl;
	compare_and_print(ft1.size(), std1.size());
	compare_and_print(ft2.size(), std2.size());
	compare_and_print(ft3.size(), std3.size());
	std::cout << std::endl;
	std::cout << YELLOW<<"compare empty of vectors" <<RESET << std::endl;
	compare_and_print(ft1.empty(), std1.empty());
	compare_and_print(ft2.empty(), std2.empty());
	compare_and_print(ft3.empty(), std3.empty());
	std::cout << std::endl;
	std::cout << YELLOW<<"compare capacity of vector" <<RESET << std::endl;
	compare_and_print(ft1.capacity(), std1.capacity());
	compare_and_print(ft2.capacity(), std2.capacity());
	compare_and_print(ft3.capacity(), std3.capacity());
	std::cout << std::endl;
	std::cout << YELLOW<<"compare empty of max_size" <<RESET << std::endl;
	compare_and_print(ft1.max_size(), std1.max_size());
	compare_and_print(ft2.max_size(), std2.max_size());
	compare_and_print(ft3.max_size(), std3.max_size());
	std::cout << std::endl;
	std::cout << YELLOW<<"compare vector element" << RESET << std::endl;
	compare_vector_and_print(std1.begin(),std1.end(), ft1.begin());
	compare_vector_and_print(std2.begin(),std2.end(), ft2.begin());
	compare_vector_and_print(std3.begin(),std3.end(), ft3.begin());
	std::cout << std::endl;
	std::cout << YELLOW<<"compare reverse vector element" << RESET << std::endl;
	compare_vector_and_print(std1.rbegin(),std1.rend(), ft1.rbegin());
	compare_vector_and_print(std2.rbegin(),std2.rend(), ft2.rbegin());
	compare_vector_and_print(std3.rbegin(),std3.rend(), ft3.rbegin());
	std::cout << std::endl;
	std::cout << YELLOW<<"create new vector with = operator and compare" << RESET << std::endl;
	std::vector<int> std4 = std1;
	ft::vector<int>	ft4 = ft1;

	compare_and_print(std4.size(), ft4.size());
	compare_and_print(std1.size(), ft1.size());
	compare_and_print(std4.capacity(), ft4.capacity());
	compare_and_print(std1.capacity(), ft1.capacity());
	compare_and_print(std4.max_size(), ft4.max_size());
	compare_and_print(std1.max_size(), ft1.max_size());
	compare_and_print(std4.empty(), ft4.empty());
	compare_and_print(std1.empty(), ft1.empty());

	compare_vector_and_print(std4.begin(), std4.end(), ft4.begin());
	compare_vector_and_print(std4.begin(), std4.end(), std1.begin());
	compare_vector_and_print(ft4.begin(), ft4.end(), std4.begin());
	compare_vector_and_print(ft4.begin(), ft4.end(), ft1.begin());
	std::cout << std::endl;
	std::cout << YELLOW<<"create new vector with vector(const vector &other) and compare" << RESET << std::endl;
	std::vector<int> std5(std1);
	ft::vector<int>	ft5(ft1);
	compare_and_print(std5.size(), ft5.size());
	compare_and_print(std1.size(), ft1.size());
	compare_and_print(std5.capacity(), ft5.capacity());
	compare_and_print(std1.capacity(), ft1.capacity());
	compare_and_print(std5.max_size(), ft5.max_size());
	compare_and_print(std1.max_size(), ft1.max_size());
	compare_and_print(std5.empty(), ft5.empty());
	compare_and_print(std1.empty(), ft1.empty());

	compare_vector_and_print(std5.begin(), std5.end(), ft5.begin());
	compare_vector_and_print(std5.begin(), std5.end(), std1.begin());
	compare_vector_and_print(ft5.begin(), ft5.end(), std5.begin());
	compare_vector_and_print(ft5.begin(), ft5.end(), ft1.begin());
	std::cout << std::endl;
	std::cout << YELLOW<<"TEST ITERATOR AND ACCESS OPERATOR" <<RESET << std::endl;
	ft::vector<int>::iterator it_ft = ft5.begin();
	std::vector<int>::iterator it_std = std5.begin();
	int index = 0;
	bool ko = false;

	if (ft5.front()!=std5.front())
		std::cout << PINK << "[KO with front operator] " << RESET;
	else
		std::cout << GREEN <<"[OK]" << RESET;
	if (ft5.back() != std5.back())
		std::cout << PINK << "[KO with back operator] " << RESET;
	else
		std::cout << GREEN <<"[OK]" << RESET;
	for (; it_ft != ft5.end();it_ft++){
		if (*it_ft != *it_std){
			std::cout << PINK << "[KO with iterator*]" << RESET;
			ko = true;
			break;
		}
		if (ft5[index]!=std5[index]){
			std::cout << PINK << "[KO with [] operator] " << RESET;
			ko = true;
			break;
		}
		if (ft5.at(index)!=std5.at(index)){
			std::cout << PINK << "[KO with at() operator] " << RESET;
			ko = true;
			break;
		}
		it_std++;
		index++;
	}
	if (!ko)
		std::cout << GREEN <<"[OK]" << RESET;
	std::cout << std::endl;
	return (0);
}
