/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:58:47 by sergio            #+#    #+#             */
/*   Updated: 2026/02/12 00:09:17 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& other) : AMateria(other)
{
}

Ice& Ice::operator=(const AMateria& other)
{
	(void)other;
	return *this;
}

Ice::~Ice()
{
}

AMateria*	Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}