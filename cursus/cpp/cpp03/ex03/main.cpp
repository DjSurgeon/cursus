/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:22:59 by sergio            #+#    #+#             */
/*   Updated: 2026/02/10 11:25:29 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- 1. CONSTRUCTOR ---" << std::endl;
	DiamondTrap monster("42Clap");

	std::cout << "\n--- 2. WHO AM I ---" << std::endl;
	monster.whoAmI();

	std::cout << "\n--- 3. ATTACK ---" << std::endl;
	monster.attack("ClusterBot");

	std::cout << "\n--- 4. STATS CHECK ---" << std::endl;
	monster.highFivesGuys();
	monster.guardGate();

	std::cout << "\n--- 5. DESTRUCTOR ---" << std::endl;
	return 0;
}
