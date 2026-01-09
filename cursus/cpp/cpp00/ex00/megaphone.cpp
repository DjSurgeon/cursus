/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:50:46 by sergio            #+#    #+#             */
/*   Updated: 2026/01/09 23:12:34 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void	megaphone(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		std::string	str = argv[i];
		for (size_t j = 0; j < str.size(); j++)
			str[j] = std::toupper(str[j]);
		std::cout << str;
	}
	std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc >= 2)
		megaphone(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
