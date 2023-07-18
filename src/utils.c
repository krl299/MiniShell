/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:11:31 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/18 17:05:37 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_empty_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_is_inter(char *str)
{
	if (str[0] == '$' && str[1] == '?')
	{
		return (1);
	}
	return (0);
}

void	ft_update_shlvl(t_data *data)
{
	int		i;
	char	*tmp;
	char	*tmp_lvl;
	char	*env_var;

	i = 0;
	while (data->envp[i])
	{
		env_var = ft_get_env_var(data->envp[i]);
		if (ft_strcmp("SHLVL", env_var) == 0)
		{
			free(env_var);
			tmp_lvl = ft_itoa(ft_atoi(data->envp[i] + 6) + 1);
			tmp = ft_strjoin("SHLVL=", tmp_lvl);
			free(tmp_lvl);
			free(data->envp[i]);
			data->envp[i] = tmp;
			break ;
		}
		free(env_var);
		i++;
	}
}

void	ft_init_shell(t_data *data)
{
	int		i;
	char	*tmp;
	char	*path;
	char	*env_var;

	i = 0;
	path = getcwd(NULL, 0);
	while (data->envp[i])
	{
		env_var = ft_get_env_var(data->envp[i]);
		if (ft_strcmp("SHELL", env_var) == 0)
		{
			free(env_var);
			tmp = ft_strjoin("SHELL=", path);
			free(path);
			path = ft_strjoin(tmp, "/minishell");
			free(tmp);
			free(data->envp[i]);
			data->envp[i] = path;
			break ;
		}
		free(env_var);
		i++;
	}
	ft_update_shlvl(data);
}
