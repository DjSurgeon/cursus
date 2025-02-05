/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:56:21 by serjimen          #+#    #+#             */
/*   Updated: 2025/02/05 15:58:54 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_var(void)
{
	int			i = 1;
	static int	i = 1;

	printf("%i", i);
	printf("%i")
}