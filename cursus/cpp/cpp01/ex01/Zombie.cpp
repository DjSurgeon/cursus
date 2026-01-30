/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:52:37 by sergio            #+#    #+#             */
/*   Updated: 2026/01/30 23:22:49 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Default Constructor.
Zombie::Zombie()
{
}

/// @brief Parameterized Constructor.
Zombie::Zombie(const std::string& zombieName) : _name(zombieName)
{
}

/// @brief Destructor.
Zombie::~Zombie()
{
	std::cout << "🧠 " << _name << " say goodbye!! His brain was broken." << std::endl;
}

/// @brief Announces the zombie to stdout.
void	Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/// @brief Sets the name of an existing zombie.
/// @param name The new name to assign.
void	Zombie::setName(const std::string& name)
{
	_name = name;
}
