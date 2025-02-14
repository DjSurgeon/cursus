/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:56:40 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/14 01:28:33 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_longlen(long n)
{
	long	result;

	result = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		result++;
		n = -n;
	}
	while (n != 0)
	{
		result++;
		n /= 10;
	}
	return (result);
}
