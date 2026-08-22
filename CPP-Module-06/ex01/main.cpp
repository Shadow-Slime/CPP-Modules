#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data(10, "Hello World!");
	std::cout << "Pre Serialization: " << *data << std::endl;
	std::cout << "Pre Serialization pointer: " << data << std::endl;
	uintptr_t serialized_ptr = Serializer::serialize(data);
	std::cout << "Serialized pointer: " << serialized_ptr << std::endl;
	Data *new_ptr = Serializer::deserialize(serialized_ptr);
	std::cout << "Post Serialization: " << *new_ptr << std::endl;
	std::cout << "Post Serialization pointer: " << new_ptr << std::endl;
	delete new_ptr;
	return 0;
}