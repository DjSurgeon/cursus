/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:30:50 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/18 14:41:35 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

void	selection_sort(int arr[], int len)
{
	int	i;
	int	j;
	int	min_index;
	int temp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		min_index = i;
		while (j < len)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		i++;
	}
}

int main (void)
{
	int	i = 0;
	int	arr[] = {65, 50, 10, 0, -15, 61, 55, 22};
	
	while (i < 8)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("<==sort=>");
	selection_sort(arr, 8);
	i = 0;
	while (i < 8)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	return (0);
}