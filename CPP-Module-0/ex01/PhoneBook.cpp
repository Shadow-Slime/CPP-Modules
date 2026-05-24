/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:05:38 by ddamiba           #+#    #+#             */
/*   Updated: 2026/05/17 11:48:48 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add_contact()
{
	std::string input;

	std::cout << "Enter first name: "<< std::endl;
	getcontactinput(input, f_name);
	contacts[i].add_info(input, f_name);
	std::cout << "Enter last name: "<< std::endl;
	getcontactinput(input, l_name);
	contacts[i].add_info(input, l_name);
	std::cout << "Enter nickname: "<< std::endl;
	getcontactinput(input, n_name);
	contacts[i].add_info(input, n_name);
	std::cout << "Enter phone number: "<< std::endl;
	getcontactinput(input, p_nbr);
	contacts[i].add_info(input, p_nbr);
	std::cout << "Enter dark secret: "<< std::endl;
	getcontactinput(input, secret);
	contacts[i].add_info(input, secret);
	std::cout << std::endl;
}

void PhoneBook::print_contacts()
{
	std::string curr_info;

	std::cout << "#############################################" << std::endl;
	std::cout << "#  Index   |First name|Last  name| Nickname #" << std::endl;
	std::cout << "#############################################" << std::endl;

	if (n_contacts > 0)
	{
		for(int i = 0; i < n_contacts; i++)
		{
		std::cout << "#" << std::setw(10) << i;
		curr_info = contacts[i].get_info(f_name);
		if (curr_info.size() > 10)
			std::cout << "|" << curr_info.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << curr_info;
		curr_info = contacts[i].get_info(l_name);
		if (curr_info.size() > 10)
			std::cout << "|" << curr_info.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << curr_info;
		curr_info = contacts[i].get_info(n_name);
		if (curr_info.size() > 10)
			std::cout << "|" << curr_info.substr(0, 9) << "." << "#" << std::endl;
		else
			std::cout << "|" << std::setw(10) << curr_info << "#" << std::endl;
		std::cout << "#############################################" << std::endl;
		}
	}
	else
		{
			std::cout << "#             No Contacts Saved             #" << std::endl;
			std::cout << "#############################################" << std::endl;
		}
	std::cout << std::endl;
}

void PhoneBook::search_contact()
{
	std::string input;
	int input_num;

	print_contacts();
	if (n_contacts == 0)
		return;
	while(1)
	{
		std::cout << "Input index: " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(0);
		if (input.empty())
		{
			std::cout << "Empty input is invalid" << std::endl;
			continue;
		}
		std::istringstream iss(input);
		iss >> input_num;
		if (!std::isdigit(input[0]) || input.size() > 1 || input_num > 7)
			std::cout << "Input an integer between 0 and 7" << std::endl;
		else if (input_num + 1 > n_contacts)
			std::cout << "Contact does not exist" << std::endl;
		else
			break;
	}
	std::cout << contacts[input_num].get_info(f_name) << std::endl;
	std::cout << contacts[input_num].get_info(l_name) << std::endl;
	std::cout << contacts[input_num].get_info(n_name) << std::endl;
	std::cout << contacts[input_num].get_info(p_nbr) << std::endl;
	std::cout << contacts[input_num].get_info(secret) << std::endl;
}
