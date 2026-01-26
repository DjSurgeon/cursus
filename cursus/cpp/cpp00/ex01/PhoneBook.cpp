/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:03:22 by sergio            #+#    #+#             */
/*   Updated: 2026/01/26 19:19:29 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/// @brief Constructor
PhoneBook::PhoneBook() : _index(0), _counter(0)
{
}

/// @brief Destructor
PhoneBook::~PhoneBook()
{
}

/// @brief Adds a new contact to the phonebook.
/// If the phonebook is full, it replaces the oldest one
/// using a circular buffer logic with the modulo operator.
void	PhoneBook::addContact()
{
	std::cout << "Hi! insert the information for your new contact." << std::endl;
	_contacts[_index].setFirstName(_setData("Insert first name"));
	_contacts[_index].setLastName(_setData("Insert last name"));
	_contacts[_index].setNickName(_setData("Insert nick name"));
	_contacts[_index].setPhoneNumber(_setData("Insert phone number"));
	_contacts[_index].setDarkestSecret(_setData("Insert darkest secret"));
	std::cout << "New contact successfully added." << std::endl;
	if (_counter < 8)
		_counter++;
	_index = (_index + 1) % 8;
}

/// @brief Main search function logic.
void	PhoneBook::displayData()
{
	if (_counter == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	for (size_t i = 0; i < _counter; i++)
		_displayContact(i);
	_searchContact();
}

/// @brief Helper to get input from user.
/// @param input The prompt message to show.
/// @return The valid string entered by user.
std::string	PhoneBook::_setData(const std::string& input)
{
	std::string	temp;

	std::cout << input << ": ";
	std::getline(std::cin, temp);
	while (temp.empty())
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "Error!" << std::endl;
		std::cout << "Please insert data for your new contact" << std::endl;
		std::getline(std::cin, temp);
	}
	return (temp);
}

/// @brief Helper to ask for index and validate it.
void	PhoneBook::_searchContact()
{	
	int	j = -1;
	std::string	index;

	std::cout << "Please enter index to display" << std::endl;
	std::getline(std::cin, index);
	if (index.length() == 1 && std::isdigit(index[0]))
		j = std::atoi(index.c_str());
	if (j < 0 || j >= static_cast<int>(_counter))
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	_displayAllContactInfo(j);
}

/// @brief Truncates string to 9 chars + '.' if longer than 10.
/// @param info String to check.
/// @return Formatted string.
std::string	PhoneBook::_truncate(const std::string& info)
{
	if (info.length() > 10)
		return (info.substr(0, 9) + ".");
	return (info);
}

/// @brief Displays a single row in the summary list.
/// @param index Position in the array.
void	PhoneBook::_displayContact(size_t index)
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << _truncate(_contacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << _truncate(_contacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << _truncate(_contacts[index].getNickName()) << "|" << std::endl;
}

/// @brief Displays full details of a contact.
/// @param index Position in the array.
void	PhoneBook::_displayAllContactInfo(size_t index)
{
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "NickName: " << _contacts[index].getNickName() << std::endl;
	std::cout << "Phone Numbre: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret:" << _contacts[index].getDarkestSecret() << std::endl;
}
