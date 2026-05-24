#include "Contact.hpp"

void Contact::add_info(std::string input, contact_field info)
{
	switch(info)
	{
		case f_name:
			this->first_name = input;
			break;
		case l_name:
			this->last_name = input;
			break;
		case n_name:
			this->nickname = input;
			break;
		case p_nbr:
			this->phone_nbr = input;
			break;
		default:
			this->dark_secret = input;
			break;
	}
}

std::string Contact::get_info(contact_field info)
{
	switch(info)
	{
		case f_name:
			return(this->first_name);
		case l_name:
			return(this->last_name);
		case n_name:
			return(this->nickname);
		case p_nbr:
			return(this->phone_nbr);
		default:
			return(this->dark_secret);
	}
}

void getcontactinput(std::string &input, contact_field type)
{
	while(1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(0);
		if (input.empty())
		{
			std::cout << "Empty input is invalid" << std::endl;
			continue;
		}
		else if (type == p_nbr)
		{
			int num = 0;
			unsigned int i;
			for (i = 0; i < input.size(); i++)
			{
				if (!std::isdigit(input[i]))
				{
					std::cout << "Phone number input must be numerical" << std::endl;
					break;
				}
				num = (num * 10) + (input[i] - '0');
			}
			if (i != input.size())
				continue;
			if (num < MIN_PHONE_NBR || num > MAX_PHONE_NBR)
			{
				std::cout << "Invalid phone number range" << std::endl;
				continue;
			}
		}
		return;
	}
}
