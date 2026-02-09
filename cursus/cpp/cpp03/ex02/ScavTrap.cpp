/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:40:39 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 20:05:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Yes!, my name is " << _name << " and I am in Promethea, where the food is strange I am always alone..." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "Well, my name is Clone" << _name << " and I am in Promethea, where the air is strange I am always not alone..." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " - GoodBye!! I think you should know that I feel very unlucky..." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks "<< target << ", agressively, causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "No way!, I'm out of fuel!!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
