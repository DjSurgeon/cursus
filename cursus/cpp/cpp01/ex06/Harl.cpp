/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:03:07 by sergio            #+#    #+#             */
/*   Updated: 2026/02/03 14:03:38 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::filter(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			selectedLevel = -1;
	for (size_t i = 0; i < 4; i++)
	{
		if (level.compare(levels[i]) == 0)
		{
			selectedLevel = i;
			break ;
		}
	}
	switch (selectedLevel)
	{
		case 0:
			(this->debug)();
			// Fallthrough
		case 1:
			(this->info)();
			// Fallthrough
		case 2:
			(this->warning)();
			// Fallthrough
		case 3:
			(this->error)();
			break ;
		default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}