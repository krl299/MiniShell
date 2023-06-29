/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:17:40 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/29 19:20:33 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_count_args(t_token *tokens)
{
	int		i;
	t_token	*aux;

	i = 0;
	aux = tokens;
	while (aux->next != NULL && aux->next->type == NO_QUOTE)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

static char	**ft_create_args(t_token *tokens)
{
	int		count_args;
	char	**args;
	t_token	*aux;
	int		i;

	count_args = ft_count_args(tokens);
	args = malloc(sizeof(char **) * count_args);
	aux = tokens->next;
	i = 0;
	while (aux && count_args > 0)
	{
		args[i] = aux->string;
		aux = aux->next;
		i++;
		count_args--;
	}
	return (args);
}

void	ft_built(t_token *tokens)
{
	char	**args;

	if (ft_strcmp(tokens->string, "pwd") == 0)
		ft_built_pwd();
	else if (ft_strcmp(tokens->string, "echo") == 0)
	{
		args = ft_create_args(tokens);
		ft_built_echo(args);
		free(args);
	}
	else if (ft_strcmp(tokens->string, "cd") == 0)
	{

	}
	else if (ft_strcmp(tokens->string, "export") == 0)
	{

	}
	else if (ft_strcmp(tokens->string, "unset") == 0)
	{

	}
	else if (ft_strcmp(tokens->string, "env") == 0)
	{

	}
	else if (ft_strcmp(tokens->string, "exit") == 0)
	{

	}
}
