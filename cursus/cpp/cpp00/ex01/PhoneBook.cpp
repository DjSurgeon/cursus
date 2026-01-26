/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:03:22 by sergio            #+#    #+#             */
/*   Updated: 2026/01/26 15:03:29 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
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

	std::cout << data << ": ";
	std::getline(std::cin, temp);
	while (temp.empty())
	{
		if (std::cin.eof())
			exit(-1);
		std::cout << "Error!" << std::endl;
		std::cout << "Please insert data for your new contact" << std::endl;
		std::getline(std::cin, temp);
	}
	return (temp);
}

std::string	PhoneBook::_truncate(const std::string& str)
{
	return (str.substr(0, 9) + ".");
}

void	PhoneBook::_display_contact(size_t index)
{
	std::string temp;

	std::cout << std::setw(10) << index << "|";
	if (_contacts[index].get_first().length() > 10)
	{
		temp = _contacts[index].get_first();
		std::cout << std::setw(10) << _truncate(temp) << "|";
	}
	else
		std::cout << std::setw(10) << _contacts[index].get_first() << "|";
	if (_contacts[index].get_last().length() > 10)
	{
		temp = _contacts[index].get_last();
		std::cout << std::setw(10) << _truncate(temp) << "|";
	}
	else
		std::cout << std::setw(10) << _contacts[index].get_last() << "|";
	if (_contacts[index].get_nick().length() > 10)
	{
		temp = _contacts[index].get_nick();
		std::cout << std::setw(10) << _truncate(temp) << "|" << std::endl;
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
	std::cout << "New contact successfully added." << std::endl;
	if (_count < 8)
		_count++;
	_index = (_index + 1) % 8;
}

void	PhoneBook::search_contact(int index)
{
	if (index < 0 || index >= static_cast<int>(_count))
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	_display_contact(index);
}

void	PhoneBook::display_data()
{
	std::string	index;

	if (_count == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	for (size_t i = 0; i < _count; i++)
		_display_contact(i);
	std::cout << "Please enter index to display" << std::endl;
	std::getline(std::cin, index);
	if (index.length() == 1 && std::isdigit(index[0]))
	{
		int j = std::atoi(index.c_str());
		search_contact(j);
	}
	else
		std::cout << "Incorrect index." << std::endl;
}
