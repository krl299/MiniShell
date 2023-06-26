/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:06:10 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/26 18:32:52 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_copy_envp(t_data *data, char **envp)
{
    int	i;

	i = 0;
	while (envp[i])
		i++;
	data->envp = malloc(sizeof(char *) * (i + 1));
	if (!data->envp)
		perror("envp malloc error");
	i = 0;
	while (envp[i])
	{
		data->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	data->envp[i] = NULL;
}

void	ft_init_data(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->linebuffer = NULL;
	data->tokens = NULL;
	ft_copy_envp(data, envp);
}
