/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:31:16 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 16:41:13 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	FileReplacer sed(argv[1], argv[2], argv[3]);
	if (!sed.executeReplace())
		return (1);

	return (0);
}
