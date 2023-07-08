/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:40:47 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/08 19:37:53 by cmoran-l         ###   ########.fr       */
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
			free(var_envp);
			free(var_input);
			data->envp[i] = ft_strdup(input);
			return ;
		}
		free(var_envp);
		i++;
	}
	free(var_input);
}

static void	ft_update_cd(t_data *data)
{
//	OLDPWD = PWD > PWD = NEW_PWD
	char	*new_pwd;
	char	*old_pwd;

	new_pwd = "PWD=";
	old_pwd = "OLDPWD=";
	new_pwd = ft_strjoin(new_pwd, getcwd(NULL,0));
	old_pwd = ft_strjoin(old_pwd, ft_get_env("PWD", data));
	ft_update_env(data, new_pwd);
	ft_update_env(data, old_pwd);
	free(new_pwd);
	free(old_pwd);
}

void	ft_built_cd(t_data *data)
{
	if ((data->tokens->next == NULL || ft_strcmp(data->tokens->next->string, "") == 0))
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd");
			return ;
		}
	}
	else if (chdir(data->tokens->next->string) != 0)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(data->tokens->next->string, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(2), STDERR_FILENO);
		return ;
	}
	ft_update_cd(data);
}
