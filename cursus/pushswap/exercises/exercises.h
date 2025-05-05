/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:34:58 by serjimen          #+#    #+#             */
/*   Updated: 2025/05/05 15:56:20 by serjimen         ###   ########.fr       */
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

t_node	*create_node(int value);

#endif
