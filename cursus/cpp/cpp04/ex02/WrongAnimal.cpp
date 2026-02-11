/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:00:16 by serjimen          #+#    #+#             */
/*   Updated: 2026/02/11 10:50:16 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << _type << " was born." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "Copy " << _type << " was born." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Other "<< _type << " was born." << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "The "<< _type << " walks away..." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << _type << " makes wrong generic sound..." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}
