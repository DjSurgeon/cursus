/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:00:16 by serjimen          #+#    #+#             */
/*   Updated: 2026/02/11 12:11:56 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal was born." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "Copy AAnimal was born." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Other AAnimal was born." << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "The AAnimal walks away..." << std::endl;
}

std::string	AAnimal::getType() const
{
	return _type;
}
