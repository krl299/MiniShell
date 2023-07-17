/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:45:02 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 19:42:04 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_get_pathfd(t_data *data)
{
	char	*shell;
	char	*tmp;

	shell = ft_get_env("SHELL", data);
	tmp = ft_strjoin(shell, "/tmp/.heredoc.tmp");
	free(shell);
	return (tmp);
}

void	ft_here_doc_redir(t_data *data, int *infd)
{
	int		tmpfd;
	char	*delimiter;
	char	*tmp_str;
	char	*pathfd;

	tmp_str = data->aux_tkn->string + 2;
	delimiter = ft_strtrim(tmp_str, " ");
	printf("%s\n", delimiter);
	pathfd = ft_get_pathfd(data);
	printf("%s\n", pathfd);
	tmpfd = open(pathfd, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	tmp_str = get_next_line(STDIN_FILENO);
	while (ft_strcmp(tmp_str, delimiter) != 0)
	{
		ft_putstr_fd(tmp_str, tmpfd);
		free(tmp_str);
		tmp_str = get_next_line(STDIN_FILENO);
	}
	close(tmpfd);
	tmpfd = open(pathfd, O_RDONLY);
	free(delimiter);
	free(tmp_str);
	free(pathfd);
	if (*infd != 0)
		close(*infd);
	*infd = tmpfd;
}
