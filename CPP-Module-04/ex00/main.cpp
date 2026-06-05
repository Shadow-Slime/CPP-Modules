#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Bird.hpp"

int main()
{
{
	std::cout << "--------------------------EVERYTHING CORRECT------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* copy = new Animal(*meta);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete copy;
	delete meta;
	delete j;
	delete i;
}
{
	std::cout << "-------------------------WRONG ANIMAL AND WRONG CAT-----------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* copy = new Animal(*meta);
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete copy;
	delete meta;
	delete j;
	delete i;
}
{
	std::cout << "------------------------ADDITIONAL TESTS ---------------------------------------" << std::endl;
	const Animal &b = Bird();
	const Animal b2 = b;
	const Animal creature;
	std::cout << b.getType() << " " << std::endl;
	std::cout << b2.getType() << " " << std::endl;
	std::cout << creature.getType() << " " << std::endl;
	b.makeSound();
	b2.makeSound();
	creature.makeSound();
}

return 0;
}