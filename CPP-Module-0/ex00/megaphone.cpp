/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:57:49 by daniel            #+#    #+#             */
/*   Updated: 2026/02/25 16:31:41 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for(int i = 1; argv[i]; i++)
	{
		std::string s = argv[i];
		for (unsigned int j = 0; j < s.length(); j++)
			s[j] = toupper(s[j]);
		std::cout << s;
	}
	std::cout << std::endl;
	return 0;
}
