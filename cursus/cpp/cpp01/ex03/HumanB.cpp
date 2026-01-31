/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:58:12 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 03:02:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _type(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if (_type == NULL)
	{
		std::cout << _name << " is unarmed" << std::endl;
	}
	else
	{
		std::cout << _name << " attacks with their " << _type->getType() << std::endl;
	}
}

const std::string& HumanB::getName() const
{
	return (_name);
}

void	HumanB::setWeapon(Weapon& type)
{
	_type = &type;
}
