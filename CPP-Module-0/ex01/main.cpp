#include "PhoneBook.hpp"

int main(void)
{
	std::string input;
	PhoneBook book;

	book.i = 0;
	book.n_contacts = 0;
	std::cout << "Enter command: (ADD, SEARCH, EXIT)" << std::endl;
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(0);
		if (input.compare("ADD") == 0)
		{
			book.add_contact();
			if (book.n_contacts < 8)
				book.n_contacts++;
			if (book.i < 7)
				book.i++;
			else
				book.i = 0;
		}
		if (input.compare("SEARCH") == 0)
			book.search_contact();
		if (input.compare("EXIT") == 0)
			break;
		std::cout << "Enter command: " << std::endl;
	}
	return 0;
}