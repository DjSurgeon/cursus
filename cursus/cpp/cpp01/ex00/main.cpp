/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:43:44 by sergio            #+#    #+#             */
/*   Updated: 2026/01/27 14:56:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	randomChump("Stack 1");
	Zombie* heap1 = newZombie("Heap 1");
	randomChump("Stack 2");
	Zombie* heap2 = newZombie("Heap 2");
	delete(heap1);
	randomChump("Stack 3");
	delete(heap2);
	return (0);
}
