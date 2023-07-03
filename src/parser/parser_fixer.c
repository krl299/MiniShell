/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fixer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:17:57 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/07/03 18:07:53 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		if (tmp->type == DOUBLE_QUOTE)
		{
			str = ft_strtrim(tmp->string, "\"");
			free(tmp->string);
			tmp->string = str;
		}
		else if (tmp->type == SINGLE_QUOTE)
		{
			str = ft_strtrim(tmp->string, "\'");
			free(tmp->string);
			tmp->string = str;
		}
		tmp = tmp->next;
	}
}

void	ft_set_env_variables(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		if (tmp->type == NO_QUOTE && ft_strchr(&tmp->string[0], '$'))
			tmp->type = ENVI_VAR;
		tmp = tmp->next;
	}
}
