/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:40:47 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/14 02:04:30 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_update_env(t_data *data, char *input)
{
	int		i;
	char	*var_envp;
	char	*var_input;

	i = 0;
	var_input = ft_get_env_var(input);
	while (data->envp[i])
	{
		var_envp = ft_get_env_var(data->envp[i]);
		if (ft_strcmp(var_envp, var_input) == 0)
		{
			free(data->envp[i]);
			data->envp[i] = ft_strdup(input);
		}
		free(var_envp);
		i++;
	}
	free(var_input);
}

static void	ft_update_cd(t_data *data)
{
	char	*new_pwd;
	char	*old_pwd;
	char	*value_new_pwd;
	char	*value_old_pwd;

	new_pwd = "PWD=";
	old_pwd = "OLDPWD=";
	value_new_pwd = getcwd(NULL, 0);
	value_old_pwd = ft_get_env("PWD", data);
	new_pwd = ft_strjoin(new_pwd, value_new_pwd);
	old_pwd = ft_strjoin(old_pwd, value_old_pwd);
	ft_update_env(data, new_pwd);
	ft_update_env(data, old_pwd);
	free(new_pwd);
	free(old_pwd);
	free(value_new_pwd);
	free(value_old_pwd);
}

void	ft_built_cd(t_data *data)
{
	if ((data->aux_tkn->next == NULL || ft_strcmp(data->aux_tkn->next->string, "") == 0))
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd");
			return ;
		}
	}
	else if (chdir(data->aux_tkn->next->string) != 0)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(data->aux_tkn->next->string, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(2), STDERR_FILENO);
		return ;
	}
	ft_update_cd(data);
}
