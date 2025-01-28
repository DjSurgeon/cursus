/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:43:56 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/28 23:27:33 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
void ft_putstr(char *s);
size_t ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr (const char *big, const char *little, size_t len);

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char *s)
{
    size_t i;
    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }
    
}
size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strnstr (const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;
    
    i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
        j = 0;
        while (big[i + j] == little[j] && i + j < len)
        {
            j++;
            if (little[j + 1] != big[i + j])
				return (NULL);
            if (little[j + 1] == '\0')
                return ((char *)&big[i]);
        }
		i++;
	}
	return (NULL);
}

int main (void)
{
    char big[] = "hola mundo!";
    char little[] = "m";
    size_t len = 8;

    ft_putstr((char*)ft_strnstr(big, little, len));
    ft_putstr((char*)ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));

    return(0);
}