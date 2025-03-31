/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:49:51 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/31 15:22:30 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool	ft_isspace(char c)
{
	if(c == 32 || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (true);
	return (false);
}

bool	ft_isalphanum(char c)
{
	if(c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	is_empty_argument(int argc, char **argv)
{
	size_t	i;
	
	i = 0;
	if(argc == 1 || argc == 2 && !argv[1][0])
	{
		printf("Error ./a.out || ./a.out \"\"\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			ft_isspace(argv[1][i]);
			if(ft_isalphanum(argv[1][i]))
				return (false);
			i++;
		}
	printf("Error Empty Argument ./a.out \"      \"\n");
	}
	exit(EXIT_FAILURE);
}

bool	is_a_letter(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	if(argc != 1)
	{
		while (argv[i][j])
		{
			while (argv[i][j])
			{
				if(!ft_isalphanum(argv[i][j]))
				{
					printf("%c", argv[j][i]);
					return(false);
				}
				j++;
			}
			i++;
		}
	}
	return (true);
}

bool	check_arguments(int argc, char **argv)
{
	is_empty_argument(argc, argv);
	is_a_letter(argc, argv);
	return (true);
}


int main(int argc, char *argv[])
{
	if (check_arguments(argc, argv))
		printf("Argumentos válidos.");
	return (0);
}