/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:28:51 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 09:19:48 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

/// @brief Constructor
/// @param name The name of the human.
/// @param weapon The weapon reference.
HumanA::HumanA(const std::string& name , Weapon& weapon) : _name(name), _weapon(weapon)
{
}

/// @brief Destructor.
HumanA::~HumanA()
{
}

/// @brief Displays the attack message.
void	HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
