#include <iostream>
#include "A_Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
{
	std::cout << "------------------Basic creation and deletion--------------------" << std::endl;
	const A_Animal* j = new Dog();
	const A_Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}
{
	std::cout << "-----------------------Deep copy---------------------------------" << std::endl;
	Dog *puppy = new Dog();
	puppy->setIdea(0, "Biscuits");
	Dog *wolf = new Dog();
	*wolf = *puppy;
	std::cout << "\n" << "Puppy thinks " << puppy->getIdea(0) << "\n" << std::endl;
	std::cout << "\n" << "Wolf thinks " << wolf->getIdea(0) << "\n" << std::endl;
	delete puppy;
	std::cout << "\n" << "Wolf still thinks " << wolf->getIdea(0) << "\n" << std::endl;
	delete wolf;
	std::cout << std::endl;
	Dog bau;
	Dog woof(bau);
// 	Cat *meowy = new Cat();
// 	Cat *tiger = new 
	}
{
	std::cout << "\nWill not compile if an attempt is made to declare a static object of an abstract class\n" << std::endl;
	const A_Animal &b = Cat();
	// const A_Animal b2 = b;
	// const A_Animal creature;
	std::cout << b.getType() << " " << std::endl;
	// std::cout << b2.getType() << " " << std::endl;
	// std::cout << creature.getType() << " " << std::endl;
	b.makeSound();
	// b2.makeSound();
	// creature.makeSound();
}

return 0;
}