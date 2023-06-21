/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:33:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/21 12:49:49 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_leaks()
{
	system("leaks -q minishell");
}

static void	ft_sigint_handler()
{
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

static void	ft_set_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sigint_handler);
}

int	main(int argc, char **argv, char **envp)
{
	atexit(ft_leaks);
	char	*linebuffer;
	(void)argc;
	(void)argv;
	(void)envp;
	//ignore Ctrl-\ signal
	ft_set_signal();
	//keep getline in a loop in case interruption occurs
	while(1)
	{
		linebuffer = NULL;
		linebuffer = readline("Conchita $>");//when press TAB display files of directory
		//user pressed CTRL-D to exit
		if (linebuffer == NULL)
			break;
		//user pressed CTRL-C to redisplay prompt
		//signal(SIGINT, ft_sigint_handler);
		//while is empty, not do it nothing
		if (ft_strncmp(linebuffer, "", strlen(linebuffer)) == 0 || ft_empty_line(linebuffer) == 0)
		{
			free(linebuffer);
			continue;
		}
		add_history(linebuffer);
		//lexically analyze and build a list of tokens
		//ft_lexer(linebuffer);
		//parse the tokens into an abstract syntax tree
		//ft_parser();
		//free the structures
		free(linebuffer);
	}
	rl_clear_history();
	return (0);
}
