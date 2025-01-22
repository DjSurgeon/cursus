/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:42:26 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/22 12:53:49 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

#include <unistd.h>

int	ft_isspace(int c)
{
	if (c == 32 || c == 'f' || c == 'n'
		|| c == 'r' || c == 't' || c == 'v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
		if (*str == '-')
			sign == -1;
	str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char *new_line;

	new_line = (char *)'\n';
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write (fd, &new_line, 1);
}
void	ft_putnbr_fd(int n, int fd)
{
	char *number;

	number = ft_atoi(n);
	write(fd, &number, sizeof(number));
}

int main(void)
{
	char s[] = "hi 42!";
	int n = 42;
  
	ft_putendl_fd(s, 1);
	ft_putendl_fd(s, 1);
	ft_putnbr_fd(n, 1);
  
  	return (0);
}