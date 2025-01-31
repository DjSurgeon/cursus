/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tutor_chars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:55:11 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/31 11:58:32 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{									
	char			*greetings;					
	struct s_node	*next;			
}				hi42;				

int main(void)
{
	hi42	*root;						
	
	root = malloc(sizeof(hi42));		
		if (!root)					
			return (1);				
	root->next = malloc(sizeof(hi42));
		if (!root->next)
		{
			free(root);				
			return (1);
		}
	root->next->next = malloc(sizeof(hi42));
		if (!root->next->next)
		{
			free(root->next);		
			free(root);
			return (1);
		}
	// usamos strdup para asignar tambien memoria a las strings habria que hacer un free también de todo esto.
	root->greetings = strdup("Hola 42!");				
	root->next->greetings = strdup("Hi 42");			
	root->next->next->greetings = strdup("Bonjour 42");	
	root->next->next->next = NULL;	

	hi42	*current;	

	current = root;		
	while (current) 
	{
		printf("%s\n", current->greetings); 
		current = current->next;
	}
	
	hi42	*temp;	
	
	current = root;		
	while (current)	
	{
		temp = current->next;
		free(current);
		current = temp;	
	}

	return (0);
}