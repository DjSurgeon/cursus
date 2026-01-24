/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:03:22 by sergio            #+#    #+#             */
/*   Updated: 2026/01/24 21:05:03 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

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

	std::cout << std::setw(10);
	std::cout << index + "|";
	std::cout << std::setw(10);
	if (_contacts[index].get_first().length() > 10)
	{
		temp = _contacts[index].get_first();
		std::cout << temp.replace(7, 3, 3, '.') + "|";
	}
	else
		std::cout << _contacts[index].get_first() + "|";
	std::cout << std::setw(10);
	if (_contacts[index].get_last().length() > 10)
	{
		temp = _contacts[index].get_last();
		std::cout << temp.replace(7, 3, 3, '.') + "|";
	}
	else
		std::cout << _contacts[index].get_last() + "|";
	std::cout << std::setw(10);
	if (_contacts[index].get_nick().length() > 10)
	{
		temp = _contacts[index].get_nick();
		std::cout << temp.replace(7, 3, 3, '.') + "|" << std::endl;
	}
	else
		std::cout << _contacts[index].get_nick() + "|" << std::endl;
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
	_count++;
	_index = (_index + 1) % 8;
}

void	PhoneBook::search_contact(int index)
{
	if (_count == 0)
	{
		std::cout << "PhoneBook empty, please add a contact." << std::endl;
		return ;
	}
	if (index > _index || index < 0)
	{
		std::cout << "Index out of range, please try again." << std::endl;
		return ;
	}
	_display_contact(index);
}

void	PhoneBook::display_data()
{
	std::string temp;

	for (size_t i = 0; i < _index; i++)
	{
		std::cout << std::setw(10);
		std::cout << i + "|";
		std::cout << std::setw(10);
		if (_contacts[i].get_first().length() > 10)
		{
			temp = _contacts[i].get_first();
			std::cout << temp.replace(7, 3, 3, '.') + "|";
		}
		else
			std::cout << _contacts[i].get_first() + "|";
		std::cout << std::setw(10);
		if (_contacts[i].get_last().length() > 10)
		{
			temp = _contacts[i].get_last();
			std::cout << temp.replace(7, 3, 3, '.') + "|";
		}
		else
			std::cout << _contacts[i].get_last() + "|";
		std::cout << std::setw(10);
		if (_contacts[i].get_nick().length() > 10)
		{
			temp = _contacts[i].get_nick();
			std::cout << temp.replace(7, 3, 3, '.') + "|" << std::endl;
		}
		else
			std::cout << _contacts[i].get_nick() + "|" << std::endl;
	}
}
