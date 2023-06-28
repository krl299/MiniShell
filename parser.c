/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:42:13 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/28 19:49:07 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

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

void	ft_create_tokens(t_data *data)
{
	ft_parse_data(data);
}
