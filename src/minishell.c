/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:33:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/13 00:29:21 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

static void	ft_command(t_data *data, int infd, int outfd, int pipe)
{
	int	exist_redir;

	exist_redir = 0;
	while (data->aux_tkn && data->aux_tkn->type != 7)
	{
		if (data->aux_tkn->type == IN_RED || data->aux_tkn->type == OUT_RED || data->aux_tkn->type == APPEND_RED || data->aux_tkn->type == HERE_DOC_RED)
		{
			exist_redir = 1;
			break;
		}
		data->aux_tkn = data->aux_tkn->prev;
	}
	if (exist_redir)//there are a redirecction before last token or pipe
		ft_redir(data, &infd, &outfd);
	else
		ft_process_commands(data);//, infd, outfd);//need files because there are pipes after
}
		

static void	ft_do_commands(t_data *data)
{
	int		c_pipes;
	int		i;
	int		pipefd[2];
	int		infd;

	c_pipes = 0;
	infd = STDIN_FILENO;
	data->aux_tkn = data->tokens;
	while (data->aux_tkn)
	{
		if (data->aux_tkn->type == PIPE)
			c_pipes++;
		data->aux_tkn = data->aux_tkn->next;
	}
	i = 0;
	data->aux_tkn = data->tokens;
	while (i <= c_pipes && data->aux_tkn)
	{
		if (pipe(pipefd) == -1)
			perror("pipe");
		if (i == c_pipes)
			ft_command(data, infd, STDOUT_FILENO, i);
		else
			ft_command(data, infd, pipefd[1], i);
		close(pipefd[1]);
		infd = pipefd[0];
		while (data->aux_tkn && data->aux_tkn->type != PIPE)
			data->aux_tkn = data->aux_tkn->next;
		if (data->aux_tkn && data->aux_tkn->type == PIPE)
			data->aux_tkn = data->aux_tkn->next;
		i++;
	}
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
		ft_print_tokens(&data); // To be removed
		ft_do_commands(&data);
//		ft_process_commands(&data);
		ft_clean_tokens(&data);
	}
	ft_clean_exit(EXIT_SUCCESS, &data);
	return (0);
}
