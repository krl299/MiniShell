/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:26:19 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/07/11 16:13:59 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_path(t_data *data)
{
	char	*path;

	path = ft_get_env("PATH", data);
	if (path == NULL)
		return ("");
	return (path);
}

void	ft_replace_path(t_data *data)
{
	char	*aux;
	char	**paths;
	int		c;

	aux = ft_get_path(data);
	paths = ft_split(aux, ':');
	c = 0;
	if (ft_strcmp(aux, "") != 0)
		free (aux);
	while (paths[c] && ft_strcmp(paths[c], "") != 0)
	{
		aux = ft_strjoin(paths[c], "/");
		free (paths[c]);
		paths[c] = ft_strjoin(aux, data->tokens_str[0]);
		free (aux);
		if (access(paths[c], F_OK) == 0
			&& ft_strnstr(data->tokens_str[0], "./", 3) == 0)
		{
			free(data->tokens_str[0]);
			data->tokens_str[0] = ft_strdup(paths[c]);
			break ;
		}
		c++;
	}
	ft_free_str_array(paths);
}
