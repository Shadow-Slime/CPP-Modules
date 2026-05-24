#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib> 
#include <sstream>
#define MIN_PHONE_NBR 100000000
#define MAX_PHONE_NBR 999999999

typedef enum Contact_field
{
	f_name,
	l_name,
	n_name,
	p_nbr,
	secret
} contact_field;

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_nbr;
		std::string dark_secret;
	public:
		void add_info(std::string input, contact_field info);
		std::string get_info(contact_field info);
};

void getcontactinput(std::string &input, contact_field type);

#endif