/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:40:03 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 19:08:42 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**ft_cpy_env_less_one(char **envp, int x)
{
	int		i;
	int		j;
	char	**new_envp;

	i = 0;
	j = 0;
	while (envp[i])
		i++;
	new_envp = malloc(sizeof(char **) * i - 1);
	i = 0;
	while (envp[i])
	{
		if (i == x)
			free(envp[i]);
		else
		{
			new_envp[j] = envp[i];
			j++;
		}
		i++;
	}
	new_envp[j] = NULL;
	free(envp);
	return (new_envp);
}

void	ft_built_unset(t_data *data)
{
	int		i;
	char	*arg;
	char	*envp_str;

	i = 0;
	if (data->tokens->next)
	{
		arg = data->tokens->next->string;
		while (data->envp[i])
		{
			envp_str = ft_get_env_var(data->envp[i]);
			if (ft_strcmp(envp_str, arg) == 0)
			{
				data->envp = ft_cpy_env_less_one(data->envp, i);
				free(envp_str);
				break ;
			}
			free(envp_str);
			i++;
		}
	}
}
