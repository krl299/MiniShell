/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:20:01 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/09 19:55:24 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-')
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

void	ft_built_echo(char **input)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (input[i] && ft_is_n(input[i]) == 1)
	{
		flag = 1;
		i++;
	}
	while (input[i] && ft_is_n(input[i]) == 1)
		i++;
	while (input[i])
	{
		ft_putstr_fd(input[i], STDOUT_FILENO);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
