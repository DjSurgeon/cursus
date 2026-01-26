/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:14:37 by sergio            #+#    #+#             */
/*   Updated: 2026/01/26 15:03:24 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void	instructions(void)
{
	std::cout << "Welcome to the 80's awesome phonebook." << std::endl;
	std::cout << "Use: \"ADD\": to add a contact." <<std::endl;
	std::cout << "Use: \"SEARCH\": to search a contact." <<std::endl;
	std::cout << "Use: \"EXIT\": to say goodbye." <<std::endl;
	std::cout << "Enjoy!!." <<std::endl;
}

void	phonebook(void)
{
	PhoneBook	person;
	std::string	command;

	instructions();
	while (std::getline(std::cin, command))
	{
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
			std::cout << "Unknown command, try again" << std::endl;
			instructions();
		}
	}
}

int	main(void)
{
	phonebook();

	return (0);
}