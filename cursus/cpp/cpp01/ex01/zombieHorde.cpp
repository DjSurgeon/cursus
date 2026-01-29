/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:29:53 by serjimen          #+#    #+#             */
/*   Updated: 2026/01/29 12:50:26 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	if (n < 0)
		return (NULL);
	Zombie* horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		std::cout << "Zombie number: " << i << std::endl;
		horde[i].setName(name);
		horde[i].announce();
	}
	std::cout << n << " Zombies created..." << std::endl;
	return (horde);
}
