/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:22:59 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 20:48:49 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- CREATING SCAVTRAP ---" << std::endl;
	FragTrap fragbot("BotBot"); 

	std::cout << "\n--- TESTING STATS & ATTACK ---" << std::endl;
	fragbot.attack("JamesLock"); 

	std::cout << "\n--- TESTING NEW ABILITY ---" << std::endl;
	fragbot.highFivesGuys();

	std::cout << "\n--- DESTRUCTION ---" << std::endl;

	return 0;
}