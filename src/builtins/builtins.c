/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:17:40 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/11 18:23:29 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static int	ft_count_args(t_token *tokens)
// {
// 	int		i;
// 	t_token	*aux;

// 	i = 0;
// 	aux = tokens;
// 	while (aux->next != NULL && (aux->next->type == NO_QUOTE || \
// 			aux->next->type == SINGLE_QUOTE || aux->next->type == DOUBLE_QUOTE || aux->next->type == BUILTINS))
// 	{
// 		i++;
// 		aux = aux->next;
// 	}
// 	return (i);
// }

// static char	**ft_create_args(t_token *tokens)
// {
// 	int		count_args;
// 	char	**args;
// 	t_token	*aux;
// 	int		i;

// 	count_args = ft_count_args(tokens);
// 	args = malloc(sizeof(char **) * count_args + 1);
// 	aux = tokens->next;
// 	i = 0;
// 	while (aux && count_args > 0)
// 	{
// 		if (i != 0 && ft_is_n(aux->prev->string) && aux->has_space == 1)
// 			args[i] = ft_strjoin("", aux->string);
// 		else if (i != 0 && aux->has_space == 1)
// 			args[i] = ft_strjoin(" ", aux->string);
// 		else
// 			args[i] = ft_strjoin("", aux->string);
// 		aux = aux->next;
// 		i++;
// 		count_args--;
// 	}
// 	args[i] = NULL;
// 	return (args);
// }

void	ft_built(t_data *data)
{
	//char	**args;

	if (ft_strcmp(data->tokens->string, "pwd") == 0)
		ft_built_pwd();
	else if (ft_strcmp(data->tokens->string, "echo") == 0)
	{
		//args = ft_create_args(data->tokens);
		ft_built_echo(data->tokens);
		//ft_free_str_array(args);
	}
	else if (ft_strcmp(data->tokens->string, "cd") == 0)
	{
		ft_built_cd(data);
	}
	else if (ft_strcmp(data->tokens->string, "export") == 0)
	{
		ft_built_export(data);
	}
	else if (ft_strcmp(data->tokens->string, "unset") == 0)
	{
		ft_built_unset(data);
	}
	else if (ft_strcmp(data->tokens->string, "env") == 0)
	{
		ft_built_env(data);
	}
	else if (ft_strcmp(data->tokens->string, "exit") == 0)
	{
		ft_built_exit(data);
	}
}
