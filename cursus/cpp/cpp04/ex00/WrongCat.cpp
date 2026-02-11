/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:05:18 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 10:50:12 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << _type << "was born." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "Copy " << _type << " was born." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	WrongAnimal::operator=(other);
	std::cout << "Other "<< _type << " was born." << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "The "<< _type << " walks away..." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << _type << " makes wrong meow meow ..." << std::endl;
}


