/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:47:58 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 12:27:21 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	description: print a number in file descriptor number
**	parameters: int number and file descriptor
**	return:  none
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	number;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		number = (n % 10) + '0';
		write(fd, &number, 1);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		number = (n % 10) + '0';
		write(fd, &number, 1);
	}
}
