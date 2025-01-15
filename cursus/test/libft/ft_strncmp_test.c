/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:47:41 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/15 14:39:53 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_putchar(char c);

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    i = 0;
    while (i <= n)
    {
        if (s1[i] == s2[i])
        {
            i++;
        }
        else if (s1[i] > s2[i])
        {
            return (1);
        }
        else if (s1[i] < s2[i])
        {
            return (2); // return -1
        }
    }
    return (0);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
int main (void)
{
    char s1[] = "abdd";
    char s2[] = "abcd";
    size_t n;
    n = 3;
    char c;

    c = ft_strncmp(s1, s2, n) + '0'; // expect 1
    ft_putchar(c);

    return (0);
}