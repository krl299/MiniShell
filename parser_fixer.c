/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fixer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:17:57 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/29 19:07:23 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fix_tokens(t_data *data)
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
