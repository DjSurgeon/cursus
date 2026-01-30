/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:43:44 by sergio            #+#    #+#             */
/*   Updated: 2026/01/30 23:17:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Main function to test Memory Allocation (Stack vs Heap).
int	main(void)
{
	randomChump("Stack 1");
	Zombie* heap1 = newZombie("Heap 1");
	heap1->announce();
	randomChump("Stack 2");
	Zombie* heap2 = newZombie("Heap 2");
	heap2->announce();
	delete heap1;
	randomChump("Stack 3");
	delete heap2;
	return (0);
}
