/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:00:16 by serjimen          #+#    #+#             */
/*   Updated: 2026/02/11 10:54:54 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal")
{
	std::cout << _type << " was born." << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Copy " << _type << " was born." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Other "<< _type << " was born." << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "The Animal walks away..." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << _type << " makes generic sound..." << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}
