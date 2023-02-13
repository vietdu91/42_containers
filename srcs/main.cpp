/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:48:56 by emtran            #+#    #+#             */
/*   Updated: 2023/02/13 13:16:28 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.hpp"

#define T1 int
#define T2 int

int main()
{
	intro_std_functions();
	test_equal();
	test_lexicographical_compare();
	test_is_integral();
	test_make_pair();
	intro_vector();
	test_vector();
	intro_map();
	test_map();
}
