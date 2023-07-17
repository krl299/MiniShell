/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:17:47 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 19:13:46 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_built_exit(t_data *data)
{
	int		i;
	t_token	*aux_tkn;

	i = 0;
	aux_tkn = data->tokens;
	while (aux_tkn)
	{
		i++;
		aux_tkn = aux_tkn->next;
	}
	if (i == 1)
		ft_clean_exit(EXIT_SUCCESS, data);
	else if (i == 2 && ft_isdigit(data->tokens->next->string[0]) == 1)
		ft_clean_exit(ft_atoi(data->tokens->next->string), data);
	else if (!ft_isdigit(data->tokens->next->string[0]))
	{
		ft_putstr_fd("exit: numeric argument required : ", STDERR_FILENO);
		ft_putstr_fd(data->tokens->next->string, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_clean_exit(EXIT_SUCCESS, data);
	}
	else
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
}
