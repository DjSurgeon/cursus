/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:14:37 by sergio            #+#    #+#             */
/*   Updated: 2026/01/24 20:55:00 by sergio           ###   ########.fr       */
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
	instructions();
	std::string	command;
	std::getline(std::cin, command);
	if (command == "ADD")
	{
		PhoneBook	person;
		person.add_contact();
	}
	else if (command == "SEARCH")
	{
		
	}
	else if (command == "EXIT")
	{
		return ;
	}
	else
	{
		instructions();
	}
}

int	main(void)
{
	while (1)
	{
		phonebook();
	}
	return (0);
}