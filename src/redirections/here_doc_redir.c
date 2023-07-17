/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:45:02 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 17:56:24 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_here_doc_redir(t_data *data, int *infd)
{
	char	*delimiter;
	char	*tmp_str;

	tmp_str = data->aux_tkn->string + 1;
	delimiter = ft_strtrim(tmp_str, " ");
	(void)infd;
}
