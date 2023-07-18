/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:45:02 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/18 02:57:23 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_get_pathfd(t_data *data)
{
	char	*shell;
	char	*tmp;

	shell = ft_get_env("SHELL", data);
	tmp = ft_strjoin(shell, "/tmp/.here_docminishell.tmp");
	free(shell);
	return (tmp);
}

static char	*ft_get_delimiter(t_token *tkn)
{
	char	*tmp_str;
	char	*aux_str;

	tmp_str = tkn->string + 2;
	aux_str = ft_strtrim(tmp_str, " ");
	tmp_str = ft_strjoin(aux_str, "\n");
	return (tmp_str);
}

void	ft_here_doc_redir(t_data *data, int *infd)
{
	int		tmpfd;
	char	*delimiter;
	char	*tmp_str;
	char	*pathfd;

	delimiter = ft_get_delimiter(data->aux_tkn);
	pathfd = ft_get_pathfd(data);
	tmpfd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tmp_str = get_next_line(STDIN_FILENO);
	while (ft_strcmp(tmp_str, delimiter) != 0)
	{
		ft_putstr_fd(tmp_str, tmpfd);
		free(tmp_str);
		tmp_str = get_next_line(STDIN_FILENO);
	}
	close(tmpfd);
	tmpfd = open(".tmp", O_RDONLY);
	free(delimiter);
	free(pathfd);
	free(tmp_str);
	if (*infd != STDIN_FILENO)
		close(*infd);
	*infd = tmpfd;
}
