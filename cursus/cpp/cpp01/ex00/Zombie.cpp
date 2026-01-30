/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:52:37 by sergio            #+#    #+#             */
/*   Updated: 2026/01/30 23:13:13 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Constructor.
Zombie::Zombie(const std::string& zombieName) : _name(zombieName)
{
	std::cout << "Hi!! I'm a Zombie! 🧟" << std::endl;
}

/// @brief Destructor.
Zombie::~Zombie()
{
	std::cout << "🧠 " << _name << " Say goodbye!! His brain was broken." << std::endl;
}

/// @brief Makes the zombie announce itself to stdout.
void	Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
