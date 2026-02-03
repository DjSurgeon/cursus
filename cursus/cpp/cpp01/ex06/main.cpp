/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:03:01 by sergio            #+#    #+#             */
/*   Updated: 2026/02/03 14:00:34 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage ./harlFilter <level>" << std::endl;
		std::cout << "4 levels: [DEBUG], [INFO], [WARNING], [ERROR]" << std::endl;
	}
	else
	{
		Harl harl;

		harl.filter(argv[1]);
	}
	return (0);
}