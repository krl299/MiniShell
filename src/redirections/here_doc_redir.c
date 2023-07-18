/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:45:02 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/18 13:31:19 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

	delimiter = ft_get_delimiter(data->aux_tkn);
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
	free(tmp_str);
	if (*infd != STDIN_FILENO)
		close(*infd);
	*infd = tmpfd;
	unlink(".tmp");
}
