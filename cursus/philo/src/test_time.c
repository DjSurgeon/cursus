/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:44:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 18:02:21 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

long long	get_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

void	test_sleep(int sleep)
{
	long long	start = get_time();

	usleep(sleep * 1000);
	long long	end = get_time();
	long long	elapsed = end - start;
	printf("Esperado: %d ms | Real: %lld ms | Diferencias: %lldms\n", sleep, elapsed, elapsed - sleep);
}

void	ft_usleepv1(long long time_ms)
{
	usleep(time_ms * 1000);
}

void	ft_usleepv2(long long time_ms)
{
	long long start = get_time();
	while (get_time() - start < time_ms)
	{
		/* code */
	}
}

void	ft_usleepv3(long long time_ms)
{
	long long start = get_time();
	while (get_time() - start < time_ms)
	{
		usleep(100);
	}
}

size_t test_version(char *name, void (*sleep)(long long), int ms)
{
	long long start = get_time();
	sleep(ms);
	long long elapsed = get_time() - start;

	printf("%s: Esperado %dms → Real %lldms (Error: %+lldms)\n", name, ms, elapsed, elapsed - ms);
	return (elapsed - ms);
}


int main(void)
{
	printf("=== EJERCICIO 4: Comparar versiones de ft_usleep ===\n\n");

	size_t	i = 0;
	size_t	err1 = 0;
	size_t	err2 = 0;
	size_t	err3 = 0;
	while (i < 55)
	{
		printf("Ciclo [%li] de 55", i);
		printf("\nTest con 1ms (crítico):\n");
		err1 += test_version("v1 (usleep)", ft_usleepv1, 1);
		err2 += test_version("v2 (busy)  ", ft_usleepv2, 1);
		err3 += test_version("v3 (hybrid)", ft_usleepv3, 1);

		printf("\nTest con 3ms (crítico):\n");
		err1 += test_version("v1 (usleep)", ft_usleepv1, 3);
		err2 += test_version("v2 (busy)  ", ft_usleepv2, 3);
		err3 += test_version("v3 (hybrid)", ft_usleepv3, 3);

		printf("\nTest con 5ms (crítico):\n");
		err1 += test_version("v1 (usleep)", ft_usleepv1, 5);
		err2 += test_version("v2 (busy)  ", ft_usleepv2, 5);
		err3 += test_version("v3 (hybrid)", ft_usleepv3, 5);

		printf("Test con 10ms:\n");
		err1 += test_version("v1 (usleep)", ft_usleepv1, 10);
		err2 += test_version("v2 (busy)  ", ft_usleepv2, 10);
		err3 += test_version("v3 (hybrid)", ft_usleepv3, 10);

		printf("\nTest con 100ms:\n");
		err1 += test_version("v1 (usleep)", ft_usleepv1, 100);
		err2 += test_version("v2 (busy)  ", ft_usleepv2, 100);
		err3 += test_version("v3 (hybrid)", ft_usleepv3, 100);
		i++;
	}
	printf("Error Total v1 = %li\n", err1);
	printf("Error Total v2 = %li\n", err2);
	printf("Error Total v3 = %li\n", err3);
	return (0);
}
