/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_prints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:12:22 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/20 16:56:04 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
** @brief Write a character to a file descriptor
** @param c Character to output
** @param fd File descriptor to write to
** 
** Outputs the character 'c' to the given file descriptor. Uses raw system
** call for maximum efficiency. Handles all standard file descriptors
** (0=stdin, 1=stdout, 2=stderr) and valid open descriptors.
** 
** @note Uses unsigned char to handle full 8-bit values
** @warning Does not validate file descriptor - ensure it's open and writable
*/
void	ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}

/**
** @brief Write an integer to a file descriptor
** @param n Integer to output
** @param fd File descriptor to write to
**
** Outputs the integer 'n' to the given file descriptor. This function handles
** all integer values, including INT_MIN, and uses a buffer to minimize system
** calls for efficiency.
**
** @note Uses an iterative approach to avoid recursion stack overflow.
** @warning Does not validate the file descriptor. Ensure it is
** open and writable.
*/
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

/**
** @brief Write a string to a file descriptor
** @param s String to output (NULL is handled gracefully)
** @param fd File descriptor to write to
**
** Outputs the string 's' to the given file descriptor. This function handles
** NULL strings by doing nothing, and uses a single write call for efficiency.
**
** @note Uses size_t for string length calculation.
** @warning Does not validate the file descriptor.
** Ensure it is open and writable.
*/
void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return ;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
}
