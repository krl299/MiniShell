/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:50:30 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/07/19 16:19:20 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error(char *path, int outfd)
{
	dup2(STDOUT_FILENO, outfd);
	if (ft_strnstr(path, "./", 3) != 0 || ft_strnstr(path, "/", 2) != 0)
		perror(path);
	else
	{
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd("command not found \n", STDERR_FILENO);
	}
}

int	ft_get_tokens_count(t_data *data)
{
	int		i;
	t_token	*tmp;

	tmp = data->tokens;
	i = 0;
	while (tmp && tmp->type != PIPE && tmp->type != IN_RED
		&& tmp->type != OUT_RED && tmp->type != APPEND_RED
		&& tmp->type != HERE_DOC_RED)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**ft_create_argv(t_data *data)
{
	int		i;
	char	**argv;
	t_token	*aux;

	i = ft_get_tokens_count(data);
	argv = (char **)malloc(sizeof(char *) * (i + 1));
	if (!argv)
		ft_error("malloc", STDERR_FILENO);
	i = 0;
	aux = data->tokens;
	while (aux && aux->type != PIPE && aux->type != IN_RED
		&& aux->type != OUT_RED && aux->type != APPEND_RED
		&& aux->type != HERE_DOC_RED)
	{
		argv[i] = ft_strdup(aux->string);
		aux = aux->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

void	ft_execve(t_data *data, int infd, int outfd)
{
	pid_t	pid;
	int		status;

	ft_is_fork(1);
	pid = fork();
	if (pid == 0)
	{
		ft_replace_path(data);
		dup2(infd, STDIN_FILENO);
		dup2(outfd, STDOUT_FILENO);
		if (execve(data->tokens_str[0], data->tokens_str, data->envp) == -1)
			ft_error(data->tokens[0].string, STDOUT_FILENO);
		ft_clean_exit(EXIT_FAILURE, data);
	}
	else if (pid < 0)
		perror(data->tokens_str[0]);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (pid > 0)
		{
			if (WIFEXITED(status))
				data->id_last_proc = WEXITSTATUS(status);
		}
	}
}

void	ft_process_commands(t_data *data, int infd, int outfd)
{
	data->tokens_str = ft_create_argv(data);
	if (access(data->tokens_str[0], F_OK) == 0)
	{
		if (ft_strnstr(data->tokens_str[0], "./", 3) == 0
			&& ft_strnstr(data->tokens_str[0], "/", 2) == 0)
		{
			ft_putstr_fd(data->tokens_str[0], STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd("command not found \n", STDERR_FILENO);
			data->id_last_proc = 127;
			ft_free_str_array(data->tokens_str);
			return ;
		}
	}
	if (data->tokens[0].type == BUILTINS)
		ft_built(data, outfd);
	else
	{
		ft_execve(data, infd, outfd);
		ft_is_fork(0);
	}
	ft_free_str_array(data->tokens_str);
}
