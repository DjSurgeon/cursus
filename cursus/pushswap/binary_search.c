/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:40:27 by serjimen          #+#    #+#             */
/*   Updated: 2025/03/17 12:49:16 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	binary_search(int arr[], int number)
{
	int		low;
	int		high;
	int		mid;
	size_t	i;
	size_t counter;

	i = 0;
	low = 0;
	high = 6;
	counter = 0;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == number)
		{
			printf("The number is %d in position: %d, in %zu searchs", number, mid + 1, counter);
			return ;
		}
		else if (arr[mid] < number)
			low = mid + 1;
		else
			high = mid - 1;
		counter++;
	}
	printf("Number not found");
}

void	lineal_search(int arr[], int number)
{
	size_t	i;
	size_t	counter;
	
	i = 0;
	counter = 0;
	while (arr[i])
	{
		if (arr[i] == number)
		{
			printf("\nThe number is: %d in position: %zu, in %zu searchs", number, i, counter);
			return ;
		}
		i++;
		counter++;
	}
	printf("\nNumber not found");	
}

int main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 10, 11, 15, 19, 20, 24, 27, 29, 31, 33, 35, 36, 38, 44, 48, 50};
	// size_t	i;

	// i = 0;
	// while (i < 6)
	// {
	// 	printf("%d", arr[i]);
	// 	i++;
	// }
	lineal_search(arr, 48);
	printf("\n\n");
	binary_search(arr, 48);
		
	return (0);
}