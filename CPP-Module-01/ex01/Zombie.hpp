#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <vector>

class Zombie
{
	private:
		std::string name;
	public:
		void announce(void);
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void set_name(std::string name);

};

Zombie* zombieHorde(int N, std::string name);

#endif