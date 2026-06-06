#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound() const;
		std::string getIdea(int idea_i) const;
		void setIdea(int idea_i, std::string idea);
};

#endif