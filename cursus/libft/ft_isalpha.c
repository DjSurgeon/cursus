/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:35:47 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/13 02:01:21 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for an alphabetic character.
 *
 * Checks if the character is a letter, either uppercase or lowercase.
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphabetic, 0 otherwise.
 */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
