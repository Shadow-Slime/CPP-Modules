#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <sstream>
#include "Contact.hpp"


//first name, last name, nickname, phone number, and darkest secret

class PhoneBook
{
	private:
		Contact contacts[8];
		void print_contacts();
	public:
		void add_contact();
		void search_contact();
		int i;
		int n_contacts;
};

#endif