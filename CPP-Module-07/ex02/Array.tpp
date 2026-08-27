#include "Array.hpp"

template <typename T>Array<T>::Array() : arr(new T[1]), arr_size(0)
{
	arr[0] = 0;
}

template <typename T>Array<T>::Array(unsigned int n) : arr(new T[n]()), arr_size(n)
{
}

template <typename T>Array<T>::Array(const Array &other) : arr(new T[other.size()]), arr_size(other.size())
{
	for (unsigned int i = 0; i < size(); i++)
		arr[i] = other.arr[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		this->arr_size = other.size();
		delete [] this->arr;
		this->arr = new T[arr_size];
		for (unsigned int i = 0; i < size(); i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T> Array<T>::~Array()
{
	delete [] this->arr;
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
	if (index >= size())
		throw(std::out_of_range("out of bounds access"));
	return arr[index];
}

template <typename T> unsigned int Array<T>::size() const
{
	return (arr_size);
}