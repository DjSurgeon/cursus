/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:14:37 by sergio            #+#    #+#             */
/*   Updated: 2026/01/25 01:49:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

void	instructions()
{
	std::cout << "Welcome to the 80's awesome phonebook." << std::endl;
	std::cout << "Use: \"ADD\": to add a contact." <<std::endl;
	std::cout << "Use: \"SEARCH\": to search a contact." <<std::endl;
	std::cout << "Use: \"EXIT\": to say goodbye." <<std::endl;
	std::cout << "Enjoy!!." <<std::endl;
}

void	phonebook()
{
	PhoneBook	person;
	std::string	command;
	std::string	index;

	instructions();
	while (1)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			person.add_contact();
			continue ;
		}
		else if (command == "SEARCH")
		{
			person.display_data();
			continue ;
		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Unkown command, try again" << std::endl;
			instructions();
		}
	}
}

int	main(void)
{
	phonebook();

	return (0);
}