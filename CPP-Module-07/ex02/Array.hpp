#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstring>

template <typename T> class Array
{
	private:
		T *arr;
		unsigned int arr_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](unsigned int index);

		unsigned int size(void) const;
};

#include "Array.tpp"

#endif