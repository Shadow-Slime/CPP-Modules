#include "Zombie.hpp"

int main(void)
{
	std::cout << "Chump is created on the stack" << std::endl;
	randomChump("Chump");
	std::cout << "Dave is created on the heap" << std::endl;
	Zombie *Zomb = newZombie("Dave");
	Zomb->announce();
	delete Zomb;
	return 0;
}

//Allocating on the stack (static allocation) is the default way and what you should most often than not use
//because its faster and manages itself automatically
//Allocating on the heap (dynamic allocation) should be limited to specific scenarios such as allocating large
//variables or when you want explicit lifetime managing