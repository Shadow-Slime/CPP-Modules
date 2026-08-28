#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T> typename T::iterator easyfind(T &haystack, int needle);

#include "easyfind.tpp"

#endif