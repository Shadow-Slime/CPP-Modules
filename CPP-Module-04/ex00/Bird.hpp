#ifndef BIRD_HPP
#define BIRD_HPP

#include <iostream>
#include "Animal.hpp"

class Bird : public Animal
{
	public:
		Bird();
		Bird(const Bird &other);
		Bird &operator=(const Bird &other);
		~Bird();
		void makeSound() const;
};

#endif