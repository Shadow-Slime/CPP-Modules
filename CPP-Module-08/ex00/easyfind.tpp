#include "easyfind.hpp"

template <typename T> typename T::iterator easyfind(T &haystack, int needle)
{
	typename T::iterator i;

	i = std::find(haystack.begin(), haystack.end(), needle);
	return i;
}