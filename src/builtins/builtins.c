/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:17:40 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/14 02:08:51 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_built(t_data *data, int fd)
{
	if (ft_strcmp(data->tokens->string, "pwd") == 0)
		ft_built_pwd(fd);
	else if (ft_strcmp(data->tokens->string, "echo") == 0)
		ft_built_echo(data->tokens, fd);
	else if (ft_strcmp(data->tokens->string, "cd") == 0)
		ft_built_cd(data);
	else if (ft_strcmp(data->tokens->string, "export") == 0)
		ft_built_export(data);
	else if (ft_strcmp(data->tokens->string, "unset") == 0)
		ft_built_unset(data);
	else if (ft_strcmp(data->tokens->string, "env") == 0)
		ft_built_env(data);
	else if (ft_strcmp(data->tokens->string, "exit") == 0)
		ft_built_exit(data);
}
