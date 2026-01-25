/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:03:22 by sergio            #+#    #+#             */
/*   Updated: 2026/01/25 02:12:56 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	_index = 0;
	_count = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string	PhoneBook::_set_data(const std::string& data)
{
	std::string	temp;

	std::cout << data << std::endl;
	std::getline(std::cin, temp);
	while (temp.empty())
	{
		std::cout << "Error!" << std::endl;
		std::cout << "Please insert data for your new contact" << std::endl;
		std::getline(std::cin, temp);
	}
	return (temp);
}

void	PhoneBook::_display_contact(size_t index)
{
	std::string temp;

	std::cout << std::setw(10) << index << "|";
	if (_contacts[index].get_first().length() > 10)
	{
		temp = _contacts[index].get_first();
		std::cout << std::setw(10) << temp.substr(0, 10).replace(7, 3, 3, '.') << "|";
	}
	else
		std::cout << std::setw(10) << _contacts[index].get_first() << "|";
	if (_contacts[index].get_last().length() > 10)
	{
		temp = _contacts[index].get_last();
		std::cout << std::setw(10) << temp.substr(0, 10).replace(7, 3, 3, '.') << "|";
	}
	else
		std::cout << std::setw(10) << _contacts[index].get_last() << "|";
	if (_contacts[index].get_nick().length() > 10)
	{
		temp = _contacts[index].get_nick();
		std::cout << std::setw(10) << temp.substr(0, 10).replace(7, 3, 3, '.') << "|" << std::endl;
	}
	else
		std::cout << std::setw(10) << _contacts[index].get_nick() << "|" << std::endl;
}

void	PhoneBook::add_contact()
{
	std::cout << "Hi! insert the information for your new contact." << std::endl;
	_contacts[_index].set_first(_set_data("Insert first name"));
	_contacts[_index].set_last(_set_data("Insert last name"));
	_contacts[_index].set_nick(_set_data("Insert nick name"));
	_contacts[_index].set_phone(_set_data("Insert phone number"));
	_contacts[_index].set_dark(_set_data("Insert darkest secret"));
	std::cout << "New contact succesfully added." << std::endl;
	if (_count < 8)
		_count++;
	_index = (_index + 1) % 8;
}

void	PhoneBook::search_contact(int index)
{
	if (index < 0)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	if (_count < 8 && index >= (int)_index)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	_display_contact(index);
}

void	PhoneBook::display_data()
{
	std::string	index;

	for (size_t i = 0; i < _count; i++)
		_display_contact(i);
	std::cout << "Please enter index to display" << std::endl;
	std::getline(std::cin, index);
	if (std::isdigit(index[0]))
	{
		int j = std::atoi(index.c_str());
		search_contact(j);
	}
	else
		std::cout << "Incorrect index." << std::endl;
}
