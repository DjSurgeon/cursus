/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tutor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:55:11 by serjimen          #+#    #+#             */
/*   Updated: 2025/01/31 11:41:45 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{									
	int				n;					
	struct s_node	*next;			
}				t_node;				

int main(void)
{
	t_node	*root;						
	
	root = malloc(sizeof(t_node));		
		if (!root)					
			return (1);				
	root->next = malloc(sizeof(t_node));
		if (!root->next)
		{
			free(root);				
			return (1);
		}
	root->next->next = malloc(sizeof(t_node));
		if (!root->next->next)
		{
			free(root->next);		
			free(root);
			return (1);
		}
	
	root->n = 42;				
	root->next->n = 24;			
	root->next->next->n = 12;	
	root->next->next->next = NULL;	

	t_node	*current;	

	current = root;		
	while (current) 
	{
		printf("%d\n", current->n); 
		current = current->next;
	}
	
	t_node	*temp;	
	
	current = root;		
	while (current)	
	{
		temp = current->next;
		free(current);
		current = temp;	
	}

	return (0);
}