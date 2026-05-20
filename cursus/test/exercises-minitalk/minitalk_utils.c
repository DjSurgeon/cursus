/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:38:18 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/19 09:41:01 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**	Description: Calculates the length of a null-terminated string.
**	Parameters:
**		- s: A pointer to the string whose length is to be calculated.
**	Return:
**		- The number of characters in the string, excluding the null terminator.
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

/*
**	Description: Concatenates two null-terminated strings into a newly
	allocated string.
**	Parameters:
**	- s1: A pointer to the first null-terminated string.
**	- s2: A pointer to the second null-terminated string.
**	Return:
**	- A pointer to the newly allocated string containing the concatenation
	of s1 and s2.
**	- NULL if memory allocation fails.
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_string;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_string = malloc(len_s1 + len_s2 + 1 * sizeof(char));
	if (!new_string)
		return (NULL);
	while (i < len_s1)
	{
		new_string[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		new_string[i + j] = s2[j];
		j++;
	}
	return (new_string[i + j] = '\0', new_string);
}

/*
**	@brief Convert ASCII string to integer
**	@param str Null-terminated string to convert
**	
**	Parses the initial portion of the string as an integer, ignoring leading
**	whitespace characters (as defined by ft_isspace). Then accepts an optional
**	sign character (+ or -) followed by numerical digits. Conversion stops at
**	the first non-digit character. Follows standard atoi behavior for overflow.
**	
**	@return Integer value of the converted number
*/

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

