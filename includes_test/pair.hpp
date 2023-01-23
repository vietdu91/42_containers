/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:12:17 by emtran            #+#    #+#             */
/*   Updated: 2023/01/05 17:34:14 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace	ft {

/*		STRUCTURE		*/

	template<class T1, class T2>
	struct pair {

		/*		-- MEMBER TYPES --		*/
		typedef T1 first_type;
		typedef T2 second_type;

		/*		-- DEFAULT CONSTRUCTOR --		*/
		pair() : first(), second() {};

		/*		-- CONSTRUCTOR OVERLOAD --		*/
		pair(const T1& t1, const T2& t2) : first(t1), second(t2) {};

		template< class U1, class U2 >
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {};

		/*		-- COPY CONSTRUCTOR --		*/
		pair(const pair& src) : first(src.first), second(src.second) {};

		/*		-- COPY ASSIGNEMENT OPER. --		*/
		pair& operator=(const pair& other) {

			this->first = other.first;
			this->second = other.second;
			return (*this);
		};

		/*		-- DECONSTRUCTOR --		*/
		~pair() {};

		/*		-- MEMBER OBJECTS --		*/
		first_type first;
		second_type second;
	};

/*		NON-MEMBER FUNCTIONS		*/

	template<class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 t, T2 u) {

		return (ft::pair<T1,T2>(t, u));
	};

	template<class T1, class T2>
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {

		return (lhs.first == rhs.first) && (lhs.second == rhs.second);
	};

	template<class T1, class T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {

		return !(lhs == rhs);
	};

	template< class T1, class T2 >
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {

		return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && (lhs.second < rhs.second));
	};

	template<class T1, class T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {

		return (!rhs < lhs);
	};

	template<class T1, class T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {

		return (rhs < lhs);
	};

	template<class T1, class T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {

		return (!lhs < rhs);
	}
}

#endif
