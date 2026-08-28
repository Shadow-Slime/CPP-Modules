#include "easyfind.hpp"

template <typename T> typename T::iterator easyfind(T &haystack, int needle)
{
	typename T::iterator i;

	i = find(haystack.begin(), haystack.end(), needle);
	if (i == haystack.end())
		return (haystack.end());
	return i;
}