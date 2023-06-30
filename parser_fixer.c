/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fixer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:17:57 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/30 18:48:51 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fix_blanks_in_tokens(t_data *data)
{
	t_token	*tmp;
	char	*str;

	tmp = data->tokens;
	while (tmp)
	{
		str = ft_strtrim(tmp->string, " ");
		free(tmp->string);
		tmp->string = str;
		tmp = tmp->next;
	}
}

void	ft_set_builtins(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		if (tmp->type == NO_QUOTE && ft_is_builtin(tmp->string))
			tmp->type = BUILTINS;
		tmp = tmp->next;
	}
}

void	ft_delete_quotes(t_data *data)
{
	t_token	*tmp;
	char	*str;

	tmp = data->tokens;
	while (tmp)
	{
		if (tmp->type == DOUBLE_QUOTE || tmp->type == SINGLE_QUOTE)
		{
			str = ft_strtrim(tmp->string, "\"\'");
			free(tmp->string);
			tmp->string = str;
		}
		tmp = tmp->next;
	}
}

void	ft_process_quoted_env(t_token *token)
{
	char	*str;
	t_token	*new_token;
	t_token	*next_token;
	char	*dollar;

	str = token->string;
	new_token = NULL;
	next_token = token->next;
	dollar = ft_strchr(str, '$');
	*dollar = '\0';
	token->string = ft_strdup(str);
	token->type = DOUBLE_QUOTE;
	new_token = malloc(sizeof(t_token));
	new_token->string = ft_strdup(dollar + 1);
	new_token->type = ENVI_VAR;
	new_token->prev = token;
	new_token->next = next_token;
	token->next = new_token;
	if (next_token != NULL)
		next_token->prev = new_token;
	free(str);
}

void	ft_set_env_variables(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		if (tmp->type == NO_QUOTE && ft_strchr(&tmp->string[0], '$'))
			tmp->type = ENVI_VAR;
		else if (tmp->type == DOUBLE_QUOTE && ft_strchr(tmp->string, '$'))
			ft_process_quoted_env(tmp);
		tmp = tmp->next;
	}
}
