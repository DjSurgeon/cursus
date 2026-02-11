/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:41:56 by sergio            #+#    #+#             */
/*   Updated: 2026/02/12 00:07:07 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type)
{
}
AMateria::AMateria(const AMateria& other) : _type(other._type)
{
}
AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	return *this;
}

AMateria::~AMateria()
{
}

const std::string& AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
