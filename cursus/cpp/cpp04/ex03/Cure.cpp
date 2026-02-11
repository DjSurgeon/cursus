/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:16:50 by sergio            #+#    #+#             */
/*   Updated: 2026/02/12 00:09:39 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& other) : AMateria(other)
{
}

Cure& Cure::operator=(const AMateria& other)
{
	(void)other;
	return *this;
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}