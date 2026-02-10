/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:33:45 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 20:45:53 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Oh oh oh!!, my name is " << _name << " and I am in Eden-6, I am always sick..." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "Oh oh oh, my name is Clone" << _name << " and I am in Eden-6, I am always crazy..." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << _name << " - FragBye!! I think you should know that I feel very lonely..." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "This F#$%#K repetitive project was a total success, high five!" << std::endl;
}