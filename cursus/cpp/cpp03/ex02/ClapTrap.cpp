/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:28:54 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 21:00:49 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :	_name("CL4P-TP"),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0)
{
	std::cout << "Well, my name is " << _name << " and I am in Pandora, where the fauna is strange I am always alone..." << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0)
{
	std::cout << "Well, my name is " << _name << " and I am in Pandora, where the fauna is strange I am always alone..." << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other) :	_name(other._name),
											_hitPoints(other._hitPoints),
											_energyPoints(other._energyPoints),
											_attackDamage(other._attackDamage)
{
	std::cout << "Well, my name is Clone" << _name << " and I am in Pandora, where the flora is strange I am always not alone..." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " - Bye!! I think you should know that I feel very depressed..." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks "<< target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "No way!, stupid human!!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints < 0)
	{
		_hitPoints = 0;
		std::cout << "No way!, stupid human!!" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "Can I shoot something now? Or go up some stairs? Something exciting? BOOM - hit points -" << amount << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "I am the best robot. Yes, yes, yes, I am the best robot. Oh oh, here we go! - hit point +" << amount << std::endl;
	}
	else
	{
		std::cout << "No way!, stupid human!!" << std::endl;
	}
}