#include "Zombie.hpp"

int main(void)
{
	std::cout << "The horde is rising" << std::endl;
	int count = 10;
	Zombie* horde = zombieHorde(count, "Zombot");
	for (int i = 0; i < count; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}
