/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:04:05 by emtran            #+#    #+#             */
/*   Updated: 2023/01/12 21:24:09 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace	ft {

	template<class It1, class It2>
	bool equal(It1 first1, It1 last1, It2 first2){

		for (; first1 != last1; ++first1, ++first2) {

			if (!(*first1 == *first2))
				return false;
		}
		return true;
	}

	template<class It1, class It2, class BinaryPredicate>
	bool equal(It1 first1, It1 last1, It2 first2, BinaryPredicate p){

		for (; first1 != last1; ++first1, ++first2) {

			if (!p(*first1, *first2))
				return false;
		}
		return true;
	}
}

#endif
