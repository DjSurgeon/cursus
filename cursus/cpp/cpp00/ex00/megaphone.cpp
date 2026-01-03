/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:50:46 by sergio            #+#    #+#             */
/*   Updated: 2026/01/03 18:03:56 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	megaphone(int argc, char *argv[])
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		c;
	std::string	str;

	for(i = 1; i < (size_t)argc; i++)
	{
		str = argv[i];
		size = str.size();
		for (j = 0; j < size; j++)
		{
			c = argv[i][j];
			str[j] = toupper(c);
		}
		if (i == (size_t)argc - 1)
			std::cout << str << std::endl;
		else
			std::cout << str;
	}
}

int	main(int argc, char *argv[])
{
	if (argc >= 2)
		megaphone(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
