/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:42:13 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/07/03 15:07:27 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_tokens(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		printf("string: [%s]\n", tmp->string);
		printf("type: %d\n", tmp->type);
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
	ft_set_env_variables(data);
}
