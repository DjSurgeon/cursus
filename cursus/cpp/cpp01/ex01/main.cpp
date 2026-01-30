/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:44:16 by serjimen          #+#    #+#             */
/*   Updated: 2026/01/30 23:30:41 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N_ZOMBIES 5

int	main(void)
{
	Zombie* horde = zombieHorde(N_ZOMBIES, "Bob");
	if (horde == NULL)
	{
		std::cout << "Allocation failed" << std::endl;
		return (1);
	}
	for (int i = 0; i < N_ZOMBIES; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
