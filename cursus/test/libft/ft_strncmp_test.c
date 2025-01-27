/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:47:41 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/27 20:23:11 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_putchar(char c);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*byte1;
	unsigned char	*byte2;
	size_t			i;

	byte1 = (unsigned char *) s1;
	byte2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (byte1[i] != '\0' || byte2[i] != '\0'))
	{
		if (byte1[i] != byte2[i])
			return (byte1[i] - byte2[i]);
		i++;
	}
	return (0);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
int main (void)
{
    char s1[] = "abc";
    char s2[] = "abc";
    size_t n;
    n = 7;
    char c;

    c = ft_strncmp(s1, s2, n) + '0'; // expect 0
    ft_putchar(c);

    return (0);
}