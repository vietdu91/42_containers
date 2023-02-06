/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:18:43 by emtran            #+#    #+#             */
/*   Updated: 2023/01/03 19:43:08 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace	ft {

/*		BASIC		*/

	template <class T>
	struct is_integral {
		static const bool value = false;
	};

	template<>
	struct is_integral<bool> {
		static const bool value = true;
	};

	template<>
	struct is_integral<char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<wchar_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<short> {
		static const bool value = true;
	};

	template<>
	struct is_integral<int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<long> {
		static const bool value = true;
	};

	template<>
	struct is_integral<long long> {
		static const bool value = true;
	};

/*		SIGNED AND UNSIGNED		*/

	template<>
	struct is_integral<signed char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned short> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned long> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned long long> {
		static const bool value = true;
	};

/*		CONSTANT		*/

	template<>
	struct is_integral<const bool> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const wchar_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const short> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const long> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const long long> {
		static const bool value = true;
	};

/*		VOLATILE		*/

	template<>
	struct is_integral<volatile bool> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile wchar_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile short> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile long> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile long long> {
		static const bool value = true;
	};
}
#endif
