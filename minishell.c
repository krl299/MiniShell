/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:33:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/26 18:04:42 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_leaks()
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **envp)
{
	atexit(ft_leaks);
	char	*linebuffer;
	(void)argc;
	(void)argv;
	(void)envp;
	
	ft_set_signal();
	while(1)
	{
		linebuffer = NULL;
		linebuffer = readline("Conchita $>");
		if (linebuffer == NULL)
			break;
		if (ft_strncmp(linebuffer, "", strlen(linebuffer)) == 0 || ft_empty_line(linebuffer) == 0)
		{
			free(linebuffer);
			continue;
		}
		add_history(linebuffer);
		free(linebuffer);
	}
	rl_clear_history();
	return (0);
}
