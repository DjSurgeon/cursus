/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:13 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 15:24:56 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char *s) // imprimir cadenas
{
    size_t i;
    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }    
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_character;
	size_t		string_len;
	size_t		i;

	last_character = NULL;
	string_len = ft_strlen(s);
	i = string_len;
	while (i > 0)
	{
		if (s[i] == c)
		{
			last_character = &s[i];
   			return ((char *)last_character);

		}
		i--;
	}
	if (c == '\0')
	{
		return ((char *)last_character);
	}
	return ((char *)last_character);
}
int main (void)
{
    char string[] = "the cake is a lie!";
    char c = 'i';
    char d = '\0';
    ft_putstr(ft_strrchr(string, c)); // Expect ie!
    ft_putchar('\n');
    ft_putstr(ft_strrchr("Hello World 42!", 32)); // Expect 42 
    ft_putchar('\n');
    ft_putstr(ft_strrchr(string, d)); // Expect NULL
    
    return (0);
}