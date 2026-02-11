/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:05:18 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 11:53:14 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << _type << " was born." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Copy " << _type << " was born." << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Other "<< _type << " was born." << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "The "<< _type << " walks away..." << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const
{
	std::cout << _type << " makes woof woof..." << std::endl;
}

void	Dog::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return this->_brain->getIdea(index);
}