/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:59:09 by emtran            #+#    #+#             */
/*   Updated: 2023/02/12 19:25:41 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.hpp"

const class nullptr_t {

	public:
	   template<class T>
	   operator T*() const { return 0; }

	   template<class C, class T>
	    operator T C::*() const { return 0; }

	private:
	   void operator&() const;
} nullptr = {};


template <typename T>
void print_vector(const std::vector<T> &vector) {

	typename std::vector<T>::const_iterator iter;

	std::cout << "[ ";

	for (iter = vector.begin(); iter != vector.end(); ++iter)
		std::cout << PINK << *iter << RESET << " ";

	std::cout << "]" << std::endl;
}

void test_simplicite() {

   title_of_function("Test de la SIMPLICITE");

	// Créez un vecteur vide et vérifiez sa taille et son état vide
	title_of_test("Creation");
	std::vector<int> vec;

	print_vector(vec);
	std::cout << WHITE_B << "1. " << RESET;
	if (vec.size() == 0 && vec.empty())
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Push_back de 3 int");

	// Ajoutez des éléments au vecteur et vérifiez sa taille
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	print_vector(vec);

	std::cout << WHITE_B << "2. " << RESET;
	if (vec.size() == 3)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec[0] == 1 && vec[1] == 2 && vec[2] == 3)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Pop_back de 2 int");

	vec.pop_back();
	vec.pop_back();
	print_vector(vec);

	std::cout << WHITE_B << "3. " << RESET;
	if (vec.size() == 1)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec[0] == 1)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;
}

void test_du_chef_kebabier() {

   title_of_function("Test du chef kebabier");

	// Créez un vecteur vide et vérifiez sa taille et son état vide
	title_of_test("Creation");
	std::vector<std::string> vec;

	print_vector(vec);
	std::cout << WHITE_B << "1. " << RESET;
	if (vec.size() == 0 && vec.empty())
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Push_back de 5 std::string");

	// Ajoutez des éléments au vecteur et vérifiez sa taille
	vec.push_back("Salade");
	vec.push_back("Tomate");
	vec.push_back("Oignon");
	vec.push_back("Sauce_Blanche");
	vec.push_back("STP_CHEF !");
	print_vector(vec);

	std::cout << WHITE_B << "2. " << RESET;
	if (vec.size() == 5)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec[0] == "Salade" && vec[1] == "Tomate" && vec[2] == "Oignon")
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec[3] == "Sauce_Blanche" && vec[4] == "STP_CHEF !")
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Pop_back pour une commande malpolie");

	vec.pop_back();
	vec.pop_back();
	print_vector(vec);

	std::cout << WHITE_B << "3. " << RESET;
	if (vec.size() == 3)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec[0] == "Salade" && vec[1] == "Tomate" && vec[2] == "Oignon")
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;
}

void	test_de_la_famille_quarante() {

   	title_of_function("Test de la famille Quarante");

	title_of_test("Redimensionnement");
	std::vector<int> vec;

	for (int i = 40; i < 50; ++i) {
		vec.push_back(i);
  	}
	print_vector(vec);
	std::cout << WHITE_B << "1. " << RESET;
	if (vec.size() == 10)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 16)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Insertion d'éléments en début de vecteur");
  	vec.insert(vec.begin(), 39);
	print_vector(vec);
  	std::cout << WHITE_B << "2. " << RESET;
	if (vec.size() == 11)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.front() == 39)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 16)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Insertion d'éléments à un index donné");
  	vec.insert(vec.begin() + 5, 400);
	print_vector(vec);
  	std::cout << WHITE_B << "3. " << RESET;
	if (vec.size() == 12)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec[4] == 43)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 16)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Suppression d'éléments à un index donné");
  	vec.erase(vec.begin() + 4);
	print_vector(vec);
  	std::cout << WHITE_B << "4. " << RESET;
	if (vec.size() == 11)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec[4] == 400)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 16)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Suppression de plusieurs éléments consécutifs");
  	vec.erase(vec.begin() + 2, vec.begin() + 4);
	print_vector(vec);
  	std::cout << WHITE_B << "5. " << RESET;
	if (vec.size() == 9)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec[2] == 400)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 16)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Tri du vecteur");
	vec.push_back(-40);
	vec.push_back(0);
  	std::sort(vec.begin(), vec.end());
	print_vector(vec);
  	std::cout << WHITE_B << "6. " << RESET;
	if (vec.size() == 11)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.front() == -40)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 16)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Recherche d'un élément");
 	std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 47);
	std::vector<int>::iterator itError = std::find(vec.begin(), vec.end(), 43);
	print_vector(vec);
  	std::cout << WHITE_B << "7. " << RESET;
	if (vec.size() == 11)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (std::distance(vec.begin(), it) == 7)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (std::distance(vec.begin(), itError) == 11)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 16)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Effacement de tous les éléments");
  	vec.clear();
	print_vector(vec);
  	std::cout << WHITE_B << "8. " << RESET;
	if (vec.size() == 0)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 16)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;

	title_of_test("Réservation de l'espace pour un nombre donné d'éléments");
  	vec.reserve(100);
	print_vector(vec);
  	std::cout << WHITE_B << "9. " << RESET;
	if (vec.size() == 0)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	if (vec.capacity() == 100)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;
}

void	test_du_vortex() {

   	title_of_function("Test du Vortex");

	title_of_test("Test de l'accès à un élément en dehors des limites du vecteur");
    std::vector<int> v;
	print_vector(v);
  	std::cout << WHITE_B << "1. " << RESET;
    try
    {
        int elem = v.at(0);
		(void) elem;
		std::cout << PINK << "[" << "❌" << "] " << RESET;
    }
    catch (const std::out_of_range& e)
    {
		std::cout << GREEN <<"[" << "✅" << "] " << e.what() << RESET;
    }
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Test de la réallocation de mémoire");
  	std::cout << WHITE_B << "2. " << RESET;
	srand(time(nullptr));
    size_t initial_capacity = v.capacity();
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(rand());
        if (v.capacity() > initial_capacity)
        {
            std::cout << GREEN <<"[" << "✅" << "] " << RESET;
            initial_capacity = v.capacity();
        }
    }
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Test de la concaténation de deux vecteurs");
    std::vector<int> v2;
	print_vector(v);
    v2.push_back(rand());
    v2.push_back(rand());
	print_vector(v2);
	print_vector(v);
  	std::cout << WHITE_B << "3. " << RESET;
	if (v.size() == 10)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
    v.insert(v.end(), v2.begin(), v2.end());
	if (v.size() == 12)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;
}

void	compare_and_print(size_t p1, size_t p2){
	if (p1 == p2)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
}

template <class InputIterator1, class InputIterator2>
void	compare_vector_and_print(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
	if (ft::equal(first1, last1, first2))
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	else
		std::cout << PINK << "[" << "❌" << "] " << RESET;
}

void	test_de_matuvu(){

   	title_of_function("Test de Matuvu");

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

    title_of_test("Test de comparaison de la size des vectors");
	std::cout << WHITE_B << "1. " << RESET;
	compare_and_print(ft1.size(), std1.size());
	compare_and_print(ft2.size(), std2.size());
	compare_and_print(ft3.size(), std3.size());
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Test de comparaison des vectors vides");
	std::cout << WHITE_B << "2. " << RESET;
	compare_and_print(ft1.empty(), std1.empty());
	compare_and_print(ft2.empty(), std2.empty());
	compare_and_print(ft3.empty(), std3.empty());
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Test de comparaison de la capacite des vectors");
	std::cout << WHITE_B << "3. " << RESET;
	compare_and_print(ft1.capacity(), std1.capacity());
	compare_and_print(ft2.capacity(), std2.capacity());
	compare_and_print(ft3.capacity(), std3.capacity());
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Test de comparaison des Max_Size des vectors");
	std::cout << WHITE_B << "4. " << RESET;
	compare_and_print(ft1.max_size(), std1.max_size());
	compare_and_print(ft2.max_size(), std2.max_size());
	compare_and_print(ft3.max_size(), std3.max_size());
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Test de comparaison des elements des vectors");
	std::cout << WHITE_B << "5. " << RESET;
	compare_vector_and_print(std1.begin(),std1.end(), ft1.begin());
	compare_vector_and_print(std2.begin(),std2.end(), ft2.begin());
	compare_vector_and_print(std3.begin(),std3.end(), ft3.begin());
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Test de comparaison des elements des renverse vectors");
	std::cout << WHITE_B << "5. " << RESET;
	compare_vector_and_print(std1.rbegin(),std1.rend(), ft1.rbegin());
	compare_vector_and_print(std2.rbegin(),std2.rend(), ft2.rbegin());
	compare_vector_and_print(std3.rbegin(),std3.rend(), ft3.rbegin());
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Creation des vectors par copie d'assignation");
	std::vector<int> std4 = std1;
	ft::vector<int>	ft4 = ft1;
	std::cout << WHITE_B << "6. " << RESET;
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
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Creation des vectors par copie de constructor");
	std::vector<int> std5(std1);
	ft::vector<int>	ft5(ft1);
	std::cout << WHITE_B << "7. " << RESET;
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
	std::cout << std::endl << std::endl << std::endl;

    title_of_test("Test d'iterators");
	ft::vector<int>::iterator it_ft = ft5.begin();
	std::vector<int>::iterator it_std = std5.begin();
	int index = 0;
	bool ko = false;
	std::cout << WHITE_B << "8. " << RESET;

	if (ft5.front()!=std5.front())
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	else
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	if (ft5.back() != std5.back())
		std::cout << PINK << "[" << "❌" << "] " << RESET;
	else
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	for (; it_ft != ft5.end();it_ft++){
		if (*it_ft != *it_std){
			std::cout << PINK << "[" << "❌" << "] " << RESET;
			ko = true;
			break;
		}
		if (ft5[index] != std5[index]){
			std::cout << PINK << "[" << "❌" << "] " << RESET;
			ko = true;
			break;
		}
		if (ft5.at(index) != std5.at(index)){
			std::cout << PINK << "[" << "❌" << "] " << RESET;
			ko = true;
			break;
		}
		it_std++;
		index++;
	}
	if (!ko)
		std::cout << GREEN <<"[" << "✅" << "] " << RESET;
	std::cout << std::endl << std::endl << std::endl;
}

int test_vector() {

	test_simplicite();
	test_du_chef_kebabier();
	test_de_la_famille_quarante();
	test_du_vortex();
	test_de_matuvu();
	return (0);
}






