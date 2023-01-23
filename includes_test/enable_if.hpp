/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:05:23 by emtran            #+#    #+#             */
/*   Updated: 2023/01/09 15:20:34 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace	ft {

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {

		typedef T type;
	};
}
#endif
