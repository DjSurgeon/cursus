/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:03:42 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/04/19 11:20:37 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_buffer {
	char			*str;			// Almacena la cadena recibida
	int				bit_count;		// Contador de bits recibidos (0-8)
	char			current_char;	// Carácter en construcción
	pid_t			client_pid;		// PID del cliente actual
} 				t_buffer;

static t_buffer	g_buffer = {0};
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
**	Description: Duplicates a null-terminated string by allocating memory and
	copying its content.
**	Parameters:
**		- s: A pointer to the null-terminated string to be duplicated.
**	Return:
**		- A pointer to the newly allocated duplicate string.
**		- NULL if memory allocation fails.
*/

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen (s);
	duplicate = malloc (len + 1 * sizeof (char));
	if (!duplicate)
		return (NULL);
	while (i < len)
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

static void	reset_buffer(void) {
	free(g_buffer.str);			// Libera la memoria del buffer  
	g_buffer.str = ft_strdup("");		// Reinicia el puntero  
	g_buffer.bit_count = 0;		// Resetea el contador de bits  
	g_buffer.current_char = 0;	// Borra el carácter en construcción  
	g_buffer.client_pid = 0;	// Olvida el PID del cliente  
}

static void	handle_signal(int sig, siginfo_t *info, void *context) {
	char	temp[2];
	char	*result;
	(void)context;  // No se usa, se castea a void para evitar warnings  
    // Si es un nuevo cliente, reiniciar el buffer  
    if (g_buffer.client_pid != info->si_pid) {  
        reset_buffer();  
        g_buffer.client_pid = info->si_pid;  // Actualiza el PID  
    }  
    // Construir el carácter bit a bit (MSB first)  
    g_buffer.current_char = (g_buffer.current_char << 1);
	if (sig == SIGUSR2)
	{
		g_buffer.current_char |= 1;
	}  
    g_buffer.bit_count++;  
    // Si se han recibido 8 bits (1 byte)  
    if (g_buffer.bit_count == 8) {  
        if (g_buffer.current_char == '\0') {  
            // Fin del mensaje: imprimir y resetear  
            write(1, g_buffer.str, ft_strlen(g_buffer.str));  
            write(1, "\n", 1);  
            reset_buffer();  
        } else {  
            // Agregar el carácter al buffer  
			temp[0] = g_buffer.current_char;
			temp[1] = '\0';
            result = ft_strjoin(g_buffer.str, temp);
            free(g_buffer.str);  
            g_buffer.str = result;  
        }  
        // Reiniciar para el próximo byte  
        g_buffer.bit_count = 0;  
        g_buffer.current_char = 0;  
    }  
}

int main(void) {
    struct sigaction sa;  

    // Configurar el manejador de señales  
    sa.sa_sigaction = handle_signal;  // Usar sa_sigaction para obtener info del remitente  
    sa.sa_flags = SA_SIGINFO;         // Habilitar info detallada (siginfo_t)  
    sigemptyset(&sa.sa_mask);         // No bloquear señales durante la ejecución del manejador  

    // Registrar manejadores para SIGUSR1 y SIGUSR2  
    sigaction(SIGUSR1, &sa, NULL);  
    sigaction(SIGUSR2, &sa, NULL);  

    printf("PID: %d\n", getpid());  
    while (1)
		pause();  // Esperar señales indefinidamente  
    return (0);  
}
