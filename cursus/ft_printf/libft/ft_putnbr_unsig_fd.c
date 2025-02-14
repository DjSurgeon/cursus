/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsig_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:10:17 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/02/14 01:28:00 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsig_fd(unsigned int n, int fd)
{
	char	number;

	if (n == 0)
		write(1, "0", 1);
	else
	{
		if (n >= 10)
			ft_putnbr_unsig_fd(n / 10, fd);
		number = (n % 10) + '0';
		write(fd, &number, 1);
	}
}
