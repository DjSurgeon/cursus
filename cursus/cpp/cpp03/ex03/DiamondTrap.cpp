/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:54:40 by serjimen          #+#    #+#             */
/*   Updated: 2026/02/10 11:23:33 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " has awaken!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other)
{
	*this = other;
	std::cout << "Diamond King Clone" << this->_name << " his here!!" << std::endl;

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		ClapTrap::_name = other.ClapTrap::_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed!!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap name: " << this->_name << std::endl;
	std::cout << "I am ClapTrap name: " << ClapTrap::_name << std::endl;
}
