/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:42:49 by sergio            #+#    #+#             */
/*   Updated: 2026/02/12 00:24:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : _name(name)
{
	for (size_t i = 0; i < SLOTS; i++)
		this->_inventory[i] = NULL;
	// std::cout << "Character " << this->_name << " created" << std::endl;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (size_t i = 0; i < SLOTS; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	// std::cout << "Character copy created" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (size_t i = 0; i < SLOTS; i++)
		{
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
		for (size_t i = 0; i < SLOTS; i++)
		{
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i];
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (size_t i = 0; i < SLOTS; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	// std::cout << "Character " << _name << " destroyed" << std::endl;
}

const std::string&	Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* materia)
{
	if (!materia)
		return ;
	for (size_t i = 0; i < SLOTS; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			break ;
		}
	}
}

void	Character::unequip(int index)
{
	if (index >= 0 && index < SLOTS)
		this->_inventory[index] = NULL;
}

void	Character::use(int index, ICharacter& target)
{
	if ((index >= 0 && index < SLOTS) && (_inventory[index] != NULL))
	{
		_inventory[index]->use(target);
	}
}