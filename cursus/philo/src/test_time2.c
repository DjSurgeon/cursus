/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:05:51 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/11/07 18:11:54 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_stats {
	long long total_abs_error;    // Error absoluto total
	long long total_signed_error;  // Error con signo
	long long max_error;           // Peor caso
	int over_count;                // Veces que durmió DE MÁS
	int under_count;               // Veces que durmió DE MENOS
} t_stats;

long long	get_time_ms()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

void	test_sleep(int sleep)
{
	long long	start = get_time_ms();

	usleep(sleep * 1000);
	long long	end = get_time_ms();
	long long	elapsed = end - start;
	printf("Esperado: %d ms | Real: %lld ms | Diferencias: %lldms\n", sleep, elapsed, elapsed - sleep);
}

void	ft_usleep_v1(long long time_ms)
{
	usleep(time_ms * 1000);
}

void	ft_usleep_v2(long long time_ms)
{
	long long start = get_time_ms();
	while (get_time_ms() - start < time_ms)
		;
}

void	ft_usleep_v3(long long time_ms)
{
	long long start = get_time_ms();
	while (get_time_ms() - start < time_ms)
	{
		usleep(100);
	}
}

long long test_version_detailed(char *name, void (*sleep_func)(long long), 
								 int ms, t_stats *stats)
{
	long long start = get_time_ms();
	sleep_func(ms);
	long long elapsed = get_time_ms() - start;
	long long error = elapsed - ms;
	
	// Actualizar estadísticas
	stats->total_signed_error += error;
	stats->total_abs_error += (error < 0 ? -error : error);
	
	if (error > stats->max_error || stats->max_error == 0)
		stats->max_error = (error < 0 ? -error : error);
	
	if (error > 0)
		stats->over_count++;
	else if (error < 0)
		stats->under_count++;
	
	printf("%s: %dms → %lldms (%+lldms)\n", name, ms, elapsed, error);
	
	return (error < 0 ? -error : error);
}

int main(void)
{
	printf("=== TEST DETALLADO DE ft_usleep ===\n\n");
	
	t_stats stats_v1 = {0};
	t_stats stats_v2 = {0};
	t_stats stats_v3 = {0};
	
	int iterations = 55;
	int test_times[] = {1, 3, 5, 10, 100};
	int num_tests = 5;
	
	for (int i = 0; i < iterations; i++)
	{
		for (int j = 0; j < num_tests; j++)
		{
			int ms = test_times[j];
			
			test_version_detailed("v1", ft_usleep_v1, ms, &stats_v1);
			test_version_detailed("v2", ft_usleep_v2, ms, &stats_v2);
			test_version_detailed("v3", ft_usleep_v3, ms, &stats_v3);
		}
	}
	
	printf("\n=== RESULTADOS FINALES ===\n");
	printf("Total de tests: %d\n\n", iterations * num_tests);
	
	printf("V1 (usleep puro):\n");
	printf("  Error absoluto total:  %lld ms\n", stats_v1.total_abs_error);
	printf("  Error con signo:       %+lld ms\n", stats_v1.total_signed_error);
	printf("  Error máximo:          %lld ms\n", stats_v1.max_error);
	printf("  Durmió de más:         %d veces\n", stats_v1.over_count);
	printf("  Durmió de menos:       %d veces\n", stats_v1.under_count);
	
	printf("\nV2 (busy waiting):\n");
	printf("  Error absoluto total:  %lld ms\n", stats_v2.total_abs_error);
	printf("  Error con signo:       %+lld ms\n", stats_v2.total_signed_error);
	printf("  Error máximo:          %lld ms\n", stats_v2.max_error);
	printf("  Durmió de más:         %d veces\n", stats_v2.over_count);
	printf("  Durmió de menos:       %d veces\n", stats_v2.under_count);
	
	printf("\nV3 (híbrida):\n");
	printf("  Error absoluto total:  %lld ms\n", stats_v3.total_abs_error);
	printf("  Error con signo:       %+lld ms\n", stats_v3.total_signed_error);
	printf("  Error máximo:          %lld ms\n", stats_v3.max_error);
	printf("  Durmió de más:         %d veces\n", stats_v3.over_count);
	printf("  Durmió de menos:       %d veces\n", stats_v3.under_count);
	
	// Análisis de precisión
	printf("\n=== ANÁLISIS DE PRECISIÓN ===\n");
	printf("Promedio error absoluto:\n");
	printf("  V1: %.2f ms\n", (double)stats_v1.total_abs_error / (iterations * num_tests));
	printf("  V2: %.2f ms\n", (double)stats_v2.total_abs_error / (iterations * num_tests));
	printf("  V3: %.2f ms\n", (double)stats_v3.total_abs_error / (iterations * num_tests));
	
	return (0);
}