/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:48:56 by emtran            #+#    #+#             */
/*   Updated: 2023/01/23 18:01:17 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.hpp"

int main()
{
	//std::cout << "C KI ??? C'EST : " << _NAMESPACE << std::endl;
	intro_std_functions();
	test_equal();
	test_lexicographical_compare();
	test_is_integral();
	test_make_pair();
	test_enable_if();
	test_vector();
}
