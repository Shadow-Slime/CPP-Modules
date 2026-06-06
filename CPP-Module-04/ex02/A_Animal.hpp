#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class A_Animal
{
	protected:
		std::string type;
	public:
		A_Animal();
		A_Animal(std::string type);
		A_Animal(const A_Animal &other);
		A_Animal &operator=(const A_Animal &other);
		virtual ~A_Animal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif