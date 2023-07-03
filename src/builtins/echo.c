/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:20:01 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/03 15:06:17 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_is_n(char *str)
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
		if (input[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
