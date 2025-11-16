/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:04:47 by serjimen          #+#    #+#             */
/*   Updated: 2025/11/16 23:17:40 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_utils.c
 * @brief Contains essential utility functions (libft style) for the
 * Philosophers project, including memory allocation, string conversion, and
 * character checks.
 */
#include "philo.h"

/**
 * @file ft_calloc.c
 * @brief Allocates and zero-initializes memory for an array.
 * This function allocates memory for an array of 'nmeb' elements, each size
 * 'size' bytes, and initializes all bytes to zero. It provides protection
 * against size_t overflow by returning NULL if the multiplication of nmeb
 * and size would overflow.
 * @note The memory is set to zero using byte-by-byte initialization.
 * @note If either nmeb or size is 0, returns a unique pointer that can
 * be freed.
 * @note The returned pointer should be freed when no longer needed.
 * @param nmeb Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return void* Pointer to the allocated memory, or NULL if allocation
 * fails or if nmeb * size overflow.
 * @code
 * // Example
 * int *arr = (int *)ft_calloc(10, sizeof(int));
 * if (!arr)
 * {
 *	// Handle allocation error
 * }
 * @endcode
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total_size;
	void			*memory_pointer;
	unsigned char	*clean_memory;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	memory_pointer = malloc(total_size);
	if (!memory_pointer)
		return (NULL);
	clean_memory = (unsigned char *)memory_pointer;
	i = 0;
	while (i < total_size)
	{
		clean_memory[i] = 0;
		i++;
	}
	return (clean_memory);
}

/**
 * @file ft_atoi.c
 * @brief Converts a string to an integer (ASCII to int).
 * Parses the initial portion of a string and converts it to a 32-bit integer,
 * handling optional leading whitespace, an optional sign character (+/-),
 * and numerical digits.
 * @note Leading whitespace is skipped.
 * @note Processes optional single '+' or '-' sign character.
 * @note Stops conversion at first non-digit character.
 * @param str Null-terminated string to convert.
 * @return int The converted integer value.
 * @warning Returns 0 if no valid conversion could be performed.
 * @warning Does not validate NULL pointer input.
 * @warning Behavior is undefined on interger overflows.
 * @warning Only supports base 10 conversion.
 * @code
 * // Example
 * int val1 = ft_atoi("42"); // returns 42
 * int val2 = ft_atoi("  -123"); // returns -123
 * int val3 = ft_atoi("+999abc"); // returns 999
 * int val4 = ft_atoi("invalid"); // returns 0
 * @endcode
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

/**
 * @file ft_isdigit.c
 * @brief Checks if a character is a decimal digit.
 * Determines whether the passed character represents a decimal digit (0-9)
 * in the ASCII character set.
 * @note Only validates standard ASCII digits (0-9).
 * @param c Character to check (ASCII value).
 * @return int 1 if the character is a digit, 0 otherwise.
 * @code
 * // Example
 * ft_isdigit('5'); // returns 1
 * ft_isdigit('a'); // returns 0
 * ft_isdigit(-1); // return 0
 * @endcode
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * @file ft_isspace.c
 * @brief Check if a character is a whitespace character.
 * Determines whether the passed character is one of the standard whitespace
 * characters in ASCII:
 * - Space (' ', ASCII 32).
 * - Form feed ('\f').
 * - Newline ('\n').
 * - Carriage return ('\r').
 * - Horizontal tab ('\t').
 * - Vertical tab ('\v').
 * @note Only checks for standard ASCII whitespace characters.
 * @param c Character to check (ASCII value).
 * @return int 1 If the character is whitespace, 0 otherwise.
 * @code
 * // Example
 * ft_isspace(' '); // returns 1
 * ft_isspace('\t'); // returns 1
 * ft_isspace('a'); // returns 0
 * ft_isspace('1'); // returns 0
 * @endcode
 */

int	ft_isspace(int c)
{
	if (c == 32 || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
