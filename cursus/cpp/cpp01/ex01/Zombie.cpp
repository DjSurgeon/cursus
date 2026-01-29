/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:52:37 by sergio            #+#    #+#             */
/*   Updated: 2026/01/29 12:50:55 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(const std::string& zombieName) : _name(zombieName)
{
	std::cout << "Hi!! I'm the Zombie! 🧟" << _name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "🧠 " << _name << " say goodbye!! His brain was broken." << std::endl;
}

void	Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	_name = name;
}
