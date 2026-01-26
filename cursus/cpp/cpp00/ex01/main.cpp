/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:14:37 by sergio            #+#    #+#             */
/*   Updated: 2026/01/26 19:28:01 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

/// @brief Prints the usage instructions and available commands.
void	printInstructions()
{
	std::cout << "Welcome to the 80's awesome phonebook." << std::endl;
	std::cout << "Enter one of the following commands" << std::endl;
	std::cout << "Use: \"ADD\": to add a contact." <<std::endl;
	std::cout << "Use: \"SEARCH\": to search a contact." <<std::endl;
	std::cout << "Use: \"EXIT\": to say goodbye." <<std::endl;
	std::cout << "Enjoy!!." <<std::endl;
}

/// @brief The main application loop
void	runPhonebook()
{
	PhoneBook	book;
	std::string	command;

	printInstructions();
	while (std::getline(std::cin, command))
	{
		if (command == "ADD")
			book.addContact();
		else if (command == "SEARCH")
			book.displayData();
		else if (command == "EXIT")
			break ;
		else
		{
			std::cout << "Unknown command, try again" << std::endl;
			printInstructions();
		}
	}
}

int	main(void)
{
	runPhonebook();

	return (0);
}
