/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:34:58 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/07 12:57:48 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXERCISES_H
# define EXERCISES_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct		sss_node
{
	char*			string;
	int				value;
	double			dooble;
	struct sss_node	*next;
}					various_nodes;

various_nodes	*create_3(char *s, int i, double d);
t_node			*create_node(int value);
void			add_front(t_node **head, t_node *new_node);
void			add_back(t_node **head, t_node *new_node);

#endif
