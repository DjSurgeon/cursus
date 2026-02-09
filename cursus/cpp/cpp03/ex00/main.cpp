/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:22:59 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 19:36:15 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
	std::cout << "--- TEST 1: CREATION ---" << std::endl;
	ClapTrap robot1("Vex");
	ClapTrap robot2("Harlowe");
	ClapTrap robot3(robot1);

	std::cout << "\n--- TEST 2: ATTACK (Energy consumption) ---" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Attack #" << (i + 1) << ": ";
		robot1.attack("Roland");
	}

	std::cout << "\n--- TEST 3: TAKE DAMAGE & REPAIR ---" << std::endl;
	robot2.takeDamage(5);
	robot2.beRepaired(3);
	robot2.takeDamage(10);

	std::cout << "\n--- TEST 4: ACTING WHILE DEAD ---" << std::endl;
	robot2.attack("Lilith");
	robot2.beRepaired(10);

	std::cout << "\n--- TEST 5: DESTRUCTION ---" << std::endl;
	return (0);
}