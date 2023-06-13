/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:33:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/13 15:27:05 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_leaks()
{
	system("leaks -q minishell");
}

static void	ft_ignore_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **envp)
{
	atexit(ft_leaks);
	char	*linebuffer;
	(void)argc;
	(void)argv;
	(void)envp;
	//ignore Ctrl-\ signal
	ft_ignore_signal();
	while(1)
	{
		//keep getline in a loop in case interruption occurs
		linebuffer = readline("Conchita $>");
		if (*linebuffer == 0)
		{
			free(linebuffer);
			break;
		}
		add_history(linebuffer);
		printf("%s\n", linebuffer);
		free(linebuffer);
		//user pressed CTRL-D to exit
		//lexically analyze and build a list o tokens
		//parse the tokens into an abstract syntax tree
		//free the structures
	}
	rl_clear_history();
	return (0);
}
