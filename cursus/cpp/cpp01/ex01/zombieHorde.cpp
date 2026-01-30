/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:29:53 by serjimen          #+#    #+#             */
/*   Updated: 2026/01/30 23:30:51 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Allocates N zombies in a single allocation.
/// @param n The number of zombies to create.
/// @param name The name to give to each zombie.
/// @return A pointer to the first zombie of the horde.
Zombie*	zombieHorde(int n, const std::string& name)
{
	if (n <= 0)
		return (NULL);
	Zombie* horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		std::cout << "Zombie number: " << i + 1 << std::endl;
		horde[i].setName(name);
	}
	std::cout << n << " Zombies created..." << std::endl;
	return (horde);
}
