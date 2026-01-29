/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:52:37 by sergio            #+#    #+#             */
/*   Updated: 2026/01/29 11:50:00 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string zombieName) : _name(zombieName)
{
	std::cout << "Hi!! I'm the Zombie! 🧟" << _name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "🧠 zombie say goodbye!! His brain was broken." << std::endl;
}
