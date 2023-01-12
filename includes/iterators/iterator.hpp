/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:32:10 by emtran            #+#    #+#             */
/*   Updated: 2023/01/12 15:05:46 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace	ft {

template<
	class Category,
	class T,
	class Distance = ptrdiff_t,
    class Pointer = T*,
    class Reference = T&
> struct iterator;

}

#endif
