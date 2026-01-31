/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:58:12 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 09:37:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

/// @brief Constructor.
/// @param name The name of the human.
HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{
}

/// @brief Destructor.
HumanB::~HumanB()
{
}

/// @brief Displays the attack message.
void	HumanB::attack() const
{
	if (_weapon == NULL)
	{
		std::cout << _name << " is unarmed" << std::endl;
	}
	else
	{
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
}

/// @brief Equips the human with weapon.
/// @param weapon Reference to the weapon to equip.
void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
