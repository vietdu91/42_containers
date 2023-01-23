/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:45:42 by emtran            #+#    #+#             */
/*   Updated: 2023/01/03 17:51:21 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace	ft {

	template<class It1, class It2>
	bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2) {

    	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {

    	    if (*first1 < *first2)
    	        return true;
    	    if (*first2 < *first1)
    	        return false;
		}
    	return (first1 == last1) && (first2 != last2);
	}

	template<class It1, class It2, class Compare>
	bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2, Compare comp) {

		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {

			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
}
#endif
