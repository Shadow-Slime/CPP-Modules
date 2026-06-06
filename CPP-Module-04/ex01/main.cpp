#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
{
	std::cout << "------------------Basic creation and deletion--------------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}
{
	std::cout << "-----------------------Deep copy---------------------------------" << std::endl;
	Dog *puppy = new Dog();
	puppy->setIdea(0, "Biscuits");
	Dog *wolf = new Dog(*puppy);
	std::cout << "\n" << "Puppy thinks " << puppy->getIdea(0) << "\n" << std::endl;
	std::cout << "\n" << "Wolf thinks " << wolf->getIdea(0) << "\n" << std::endl;
	delete puppy;
	std::cout << "\n" << "Wolf still thinks " << wolf->getIdea(0) << "\n" << std::endl;
	delete wolf;
}
{
	std::cout << "-------------------------Array of animals------------------------" << std::endl;
	Animal *creatures[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			creatures[i] = new Dog();
			static_cast<Dog *>(creatures[i])->setIdea(0, "walk");
		}
		else
		{
			creatures[i] = new Cat();
			static_cast<Cat *>(creatures[i])->setIdea(0, "treat");
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << "Dog " << i + 1 << " is thinking about a " << static_cast<Dog *>(creatures[i])->getIdea(0) << std::endl;
		}
		else
			std::cout << "Cat " << i + 1 << " is thinking about a " << static_cast<Cat *>(creatures[i])->getIdea(0) << std::endl;
		std::cout << "Animal " << i + 1 << " says ";
		creatures[i]->makeSound();
		delete creatures[i];
	}
}

return 0;
}