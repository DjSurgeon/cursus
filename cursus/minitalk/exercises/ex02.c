/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:39:28 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/07 20:47:02 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	handler_function(int i)
{
	(void) i;
	printf("\nCtrl + Z\n");
}
int main(void)
{
	signal(SIGTSTP, handler_function);
	while (1)
		pause();
	return (0);
}