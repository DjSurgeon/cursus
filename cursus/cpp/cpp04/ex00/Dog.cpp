/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:05:18 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 10:50:06 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << _type << " was born." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Copy " << _type << " was born." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	Animal::operator=(other);
	std::cout << "Other "<< _type << " was born." << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "The "<< _type << " walks away..." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << _type << " makes woof woof..." << std::endl;
}
