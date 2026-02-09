/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:22:59 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 20:05:50 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- CREATING SCAVTRAP ---" << std::endl;
	ScavTrap scavy("Serena"); 

	std::cout << "\n--- TESTING STATS & ATTACK ---" << std::endl;
	scavy.attack("TargetDummy"); 

	std::cout << "\n--- TESTING NEW ABILITY ---" << std::endl;
	scavy.guardGate();

	std::cout << "\n--- DESTRUCTION ---" << std::endl;

	return 0;
}