/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:42:13 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/07/08 18:05:20 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_space(t_data *data, int cur)
{
	if (cur == 0)
		return (0);
	if (data->linebuffer[cur - 1] == ' ')
		return (1);
	return (0);
}

void	ft_format_env(t_data *data)
{
	t_token	*aux;

	aux = data->tokens;
	while (aux)
	{
		while ((aux->type == 0 || aux->type == 2)
			&& ft_strchr(aux->string, '$'))
			if (!ft_replace_var(aux, data))
				break ;
		aux = aux->next;
	}
}

void	ft_print_tokens(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		printf("string: [%s]\n", tmp->string);
		printf("type: %d\n", tmp->type);
		printf("has_space: %d\n", tmp->has_space);
		tmp = tmp->next;
	}
}

int	ft_is_builtin(char *str)
{
	if (ft_strnstr("echo cd pwd export unset env exit", str, 33))
		return (1);
	return (0);
}

void	ft_create_tokens(t_data *data)
{
	ft_parse_data(data);
	ft_set_builtins(data);
	ft_fix_blanks_in_tokens(data);
	ft_delete_quotes(data);
	ft_format_env(data);
}
