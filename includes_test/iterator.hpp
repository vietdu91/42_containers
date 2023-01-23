/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:32:10 by emtran            #+#    #+#             */
/*   Updated: 2023/01/23 19:10:32 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <algorithm>
# include <iostream>
# include <string.h>
# include <limits>
# include <utility>
# include <cstddef>
# include <stddef.h>
# include <memory>
# include <vector>

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
