/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:05:18 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 11:53:39 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << _type << " was born." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Copy " << _type << " was born." << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
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

Cat::~Cat()
{
	std::cout << "The "<< _type << " walks away..." << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << _type << " makes meow meow ..." << std::endl;
}

void	Cat::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return this->_brain->getIdea(index);
}