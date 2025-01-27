/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:42:26 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 12:19:57 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"


void	ft_putnbr_fd(int n, int fd)
{
	char	number;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
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

int main(void)
{
	char s[] = "hi 42!";
	int n = -4847772;
  
//	ft_putendl_fd(s, 1);
//	ft_putendl_fd(s, 1);
	ft_putnbr_fd(n, 1);
  
  	return (0);
}