/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:20:01 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 18:14:01 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-' && str[i + 1] == 'n')
	{
		while (str[++i])
		{
			if (str[i] != 'n')
				return (0);
		}
		return (1);
	}
	else
		return (0);
}

void	ft_built_echo(t_token *tokens, int fd)
{
	int		flag;
	t_token	*aux;
	int		first;

	flag = 0;
	first = 1;
	aux = tokens->next;
	if (aux && ft_is_n(aux->string) == 1)
	{
		flag = 1;
		aux = aux->next;
	}
	while (aux && aux->string && ft_is_n(aux->string) == 1)
		aux = aux->next;
	while (aux && aux->type != PIPE && aux->type != OUT_RED
		&& aux->type != APPEND_RED && aux->type != HERE_DOC_RED)
	{
		if (first == 0)
			if (aux->has_space == 1)
				ft_putstr_fd(" ", fd);
		first = 0;
		ft_putstr_fd(aux->string, fd);
		aux = aux->next;
	}
	if (flag == 0)
		ft_putstr_fd("\n", fd);
}
