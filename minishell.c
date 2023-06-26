/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:33:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/26 18:36:25 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	atexit(ft_leaks);
	ft_init_data(&data, argc, argv, envp);
	ft_set_signal();
	while (1)
	{
		data.linebuffer = NULL;
		data.linebuffer = readline("Conchita $>");
		if (data.linebuffer == NULL)
			break ;
		if (ft_strncmp(data.linebuffer, "", strlen(data.linebuffer)) == 0
			|| ft_empty_line(data.linebuffer) == 0)
		{
			free(data.linebuffer);
			continue ;
		}
		add_history(data.linebuffer);
		ft_create_tokens(&data);
		free(data.linebuffer);
	}
	rl_clear_history();
	return (0);
}
