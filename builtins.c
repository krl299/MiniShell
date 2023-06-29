/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:17:40 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/29 14:46:46 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	**ft_create_args(t_token *tokens)
{
	int	i;
	char	**args;

	i = 0;
	while (tokens[++i].type == NO_QUOTE)
	args = malloc(sizeof(char *) * i);
	if (!args)
		return (0);
	args[i] = 0;
	i = 0;
	while (tokens[++i].type == NO_QUOTE)
	{
		args[i - 1] = tokens[i].string;
	}
	return (args);
}

static void	ft_delete_args(char **args)
{
	char *aux;

	aux = *args;
}
void	ft_built(t_token *tokens)
{
	char **args;
	if (ft_strcmp(tokens->string, "pwd") == 0)
		ft_built_pwd();	
	else if (ft_strcmp(tokens->string, "echo") == 0)
	{
		args = ft_create_args(tokens);
		ft_built_echo(args);
		ft_delete_args(args);
	}
	else if (ft_strcmp(tokens->string, "cd") == 0)
	{

	}
	else if (ft_strcmp(tokens->string, "export") == 0)
	{

	}
	else if (ft_strcmp(tokens->string, "unset") == 0)
	{

	}
	else if (ft_strcmp(tokens->string, "env") == 0)
	{

	}
	else if (ft_strcmp(tokens->string, "exit") == 0)
	{

	}
}

void	ft_built_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		perror("pwd");
	else
	{
		ft_putstr_fd(cwd, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	free(cwd);
}

static int	ft_is_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-')
	{
		while (str[++i])
		{
			if (str[i] != 'n')
				return (0);
		}
		return (1);
	}
	else
		return (0);
}

void	ft_built_echo(char **input)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (input[i] && ft_is_n(input[i]) == 1)
	{
		flag = 1;
		i++;
	}
	while (input[i] && ft_is_n(input[i]) == 1)
		i++;
	while (input[i])
	{
		ft_putstr_fd(input[i], STDOUT_FILENO);
		if (input[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
