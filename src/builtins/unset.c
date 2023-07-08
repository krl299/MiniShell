/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:40:03 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/08 19:12:58 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_env_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

static char	**ft_cpy_env_less_one(char **envp, char **new_envp, int x)
{
	int i;
	int j;
	char	**aux;

	i = 0;
	j = 0;
	aux = envp;
	while (aux[i])
	{
		if (i == x)
			i++;
		new_envp[j] = aux[i];
		j++;
		i++;
	}
	return (new_envp);
}

void	ft_built_unset(t_data *data)
{
	int 	i;
	int		list_len;
	char	**new_envp;
	char	*arg;
	char	*envp_str;

	i = 0;
	list_len = ft_env_len(data->envp);
	arg = data->tokens->next->string;
	while (data->envp[i])
	{
		envp_str = ft_get_env_var(data->envp[i]);
		if(ft_strcmp(envp_str, arg) == 0)
		{
			new_envp = malloc(sizeof(char **) * list_len - 1);
			data->envp = ft_cpy_env_less_one(data->envp, new_envp, i);
			break;
		}
		free(envp_str);
		i++;
	}
}
