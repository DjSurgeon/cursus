/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:28:51 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 03:02:24 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name , Weapon& type) : _name(name), _type(type)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _type.getType() << std::endl;
}

const std::string& HumanA::getName() const
{
	return (_name);
}
