/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:34:50 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/06/03 23:49:51 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
chequea que la string esta vacia
*/

static bool	is_empty(char **c_array)
{
	if (c_array[0] == NULL)
		return (false);
	return (true);
}

/*
chequea que en los argumentos no haya letras
*/
static bool	is_letter(char **c_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c_array[i] != NULL)
	{
		j = 0;
		while (c_array[i][j] != '\0')
		{
			if (ft_isalpha(c_array[i][j]) == 1)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/*
chequear que en los argumentos sean digitos y delante solo haya un signo.
se evitan también signos intermedios y otras cosas que no sean digitos
*/

static bool	is_digit(char **c_array)
{
	int	i;
	int	j;

	i = 0;
	while (c_array[i] != NULL)
	{
		j = 0;
		while (c_array[i][j] != '\0')
		{
			if ((c_array[i][j] == '-' || c_array[i][j] == '+')
				&& ft_isdigit(c_array[i][j + 1]) && j == 0)
				j++;
			if (ft_isdigit(c_array[i][j]))
				j++;
			else if (!ft_isdigit(c_array[i][j]))
				return (false);
			else
				return (false);
		}
		i++;
	}
	return (true);
}
/*
chequea tambien que el numero este dentro de los int max y min
chequear que no haya numeros duplicados
*/

static bool	is_duplicated(int *i_array)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	if (i_array == NULL)
		return (false);
	while (i_array[i])
	{
		temp = i_array[i];
		j = i + 1;
		while (i_array[j])
		{
			if (temp == i_array[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/*
funcion para realizar todos los chequeos
*/
bool	check_array(char **c_array)
{
	int	i;
	int	*i_array;

	i = 0;
	if (!is_empty(c_array))
		return (ft_printf("Error\n"), false);
	if (!is_letter(c_array))
		return (ft_printf("Error\n"), false);
	if (!is_digit(c_array))
		return (ft_printf("Error\n"), false);
	i_array = char_array_to_int_array(c_array);
	if (!is_duplicated(i_array))
		return (ft_printf("Error\n"), false);
	while (i_array[i])
	{
		ft_printf("int -> %d\n", i_array[i]);
		i++;
	}
	return (true);
}
