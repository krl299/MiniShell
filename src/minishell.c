/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:33:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/19 12:12:34 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_command(t_data *data, int infd, int outfd)
{
	int	exist_redir;

	exist_redir = 0;
	ft_is_fork(0);
	while (data->aux_tkn && data->aux_tkn->type != PIPE)
	{
		if (data->aux_tkn->type == IN_RED || data->aux_tkn->type == OUT_RED
			|| data->aux_tkn->type == APPEND_RED
			|| data->aux_tkn->type == HERE_DOC_RED)
		{
			exist_redir = 1;
			break ;
		}
		data->aux_tkn = data->aux_tkn->next;
	}
	if (exist_redir)
		ft_redir(data, infd, outfd);
	else
		ft_process_commands(data, infd, outfd);
}

int	ft_count_pipes(t_data *data)
{
	int		c_pipes;
	t_token	*tmp;

	c_pipes = 0;
	tmp = data->tokens;
	while (tmp)
	{
		if (tmp->type == PIPE)
			c_pipes++;
		tmp = tmp->next;
	}
	return (c_pipes);
}

static void	ft_do_commands(t_data *data)
{
	int		c_pipes;
	int		i;
	int		pipefd[2];
	int		infd;
	t_token	*tmp;

	c_pipes = ft_count_pipes(data);
	infd = STDIN_FILENO;
	i = 0;
	data->aux_tkn = data->tokens;
	tmp = data->tokens;
	while (i <= c_pipes && data->aux_tkn)
	{
		if (pipe(pipefd) == -1)
			perror("pipe");
		if (i == c_pipes)
			ft_command(data, infd, STDOUT_FILENO);
		else
			ft_command(data, infd, pipefd[1]);
		close(pipefd[1]);
		infd = pipefd[0];
		while (data->tokens && data->tokens->type != PIPE)
			data->tokens = data->tokens->next;
		if (data->tokens && data->tokens->type == PIPE)
			data->tokens = data->tokens->next;
		data->aux_tkn = data->tokens;
		i++;
	}
	data->tokens = tmp;
}

// void	ft_leaks(void)
// {
// 	system("leaks -q minishell");
// }
// ft_print_tokens(&data); // To be removed
// atexit(ft_leaks);
int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_init_data(&data, argc, argv, envp);
	ft_init_shell(&data);
	ft_set_signal();
	while (1)
	{
		data.linebuffer = NULL;
		data.linebuffer = readline("Conchita $>");
		if (data.linebuffer == NULL)
		{
			printf("\n");
			break ;
		}
		if (ft_strncmp(data.linebuffer, "", strlen(data.linebuffer)) == 0
			|| ft_empty_line(data.linebuffer) == 0)
		{
			free(data.linebuffer);
			continue ;
		}
		add_history(data.linebuffer);
		ft_create_tokens(&data);
		ft_do_commands(&data);
		ft_clean_tokens(&data);
	}
	ft_clean_exit(EXIT_SUCCESS, &data);
	return (0);
}
