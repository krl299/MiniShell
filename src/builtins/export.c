/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:53:18 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/08 19:11:10 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_update_env(t_data *data)
{
	int		i;
	char	*var_envp;
	char	*var_input;

	i = 0;
	var_input = ft_get_env_var(data->tokens->next->string);
	while (data->envp[i])
	{
		var_envp = ft_get_env_var(data->envp[i]);
		if (ft_strcmp(var_envp, var_input) == 0)
		{
			free(data->envp[i]);
			data->envp[i] = ft_strdup(data->tokens->next->string);
			free(var_envp);
			free(var_input);
			return (1);
		}
		free(var_envp);
		i++;
	}
	free(var_input);
	return (0);	
}

static char	**ft_add_env(t_data *data, char *input)
{
	int		i;
	char	**new_envp;

	i = 0;
	while (data->envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
	i = -1;
	while (data->envp[++i])
		new_envp[i] = data->envp[i];
	new_envp[i] = ft_strdup(input);
	new_envp[i + 1] = NULL;
	return (new_envp);
}

void	ft_built_export(t_data *data)
{
	char *input;
	char *format;
	t_token *arg;

	arg = data->tokens;
	if (!arg->next || (arg->next->type != 0 && arg->next->type != 1 && arg->next->type != 2))
		ft_built_env(data);
	else if(arg->next && (arg->next->type == 0 || arg->next->type == 1 || arg->next->type == 2))
	{
		input = arg->next->string;
		format = ft_strchr(input, '=');
		if (ft_isalpha(*input) == 1 && ft_strchr(input, '=') != 0 && *(format + 1) != 0)
		{
			if (ft_update_env(data) == 0)
				data->envp = ft_add_env(data, input);
		}
	}
}
