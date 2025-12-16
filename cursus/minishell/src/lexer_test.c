/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:15:45 by sergio-jime       #+#    #+#             */
/*   Updated: 2025/09/01 17:00:13 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_token *list)
{
	t_token	*temp;

	temp = list;
	while (temp)
	{
		printf("Token [%s]\n", temp->value);
		printf("Token Type [%d]\n", temp->type);
		temp = temp->next;
	}
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("[%d]: %s\n", i, array[i]);
		i ++;
	}
	return ;
}

/* int	main(int argc, char *argv[])
{
	t_token	*token_list;
	(void)argc;
	// (void)argv;

	token_list = NULL;
	token_list = tokenizer(argv[1]);
	print_list(token_list);
	free_tokens(&token_list);
	return (0);
}
 */
