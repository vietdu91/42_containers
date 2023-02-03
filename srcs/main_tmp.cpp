#include <iostream>
#include <string.h>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstddef>
#include <stddef.h>
#include <stdio.h>
#include <memory>
#include <vector>
#include "../includes_test/stack.hpp"
#include "../includes_test/vector.hpp"
#include "../includes_test/map.hpp"
#include "../includes_test/iterator_traits.hpp"
#include "../includes_test/iterator.hpp"
#include "../includes_test/random_access_iterator.hpp"
#include "../includes_test/reverse_iterator.hpp"
#include "../includes_test/node.hpp"
#include "../includes_test/RBiterator.hpp"
#include "../includes_test/RBtree.hpp"
#include "../includes_test/enable_if.hpp"
#include "../includes_test/equal.hpp"
#include "../includes_test/lexicographical_compare.hpp"
#include "../includes_test/pair.hpp"

#define T1 int
#define T2 int

#include <map>

int main() {

	ft::map<T1, T2> const mp;
	ft::map<T1, T2>::iterator it = mp.begin(); // <-- error expected

	(void)it;
	return (0);
}

