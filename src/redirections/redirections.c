/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:25:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 08:43:47 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_redir(t_data *data, int infd, int outfd)
{
	if (data->aux_tkn->type == IN_RED)
	{
		ft_input_redir(data, &infd);
		ft_process_commands(data, infd, outfd);
	}
	else if (data->aux_tkn->type == OUT_RED)
		ft_output_redir(data, outfd);
	else if (data->aux_tkn->type == APPEND_RED)
		ft_append_redir(data, outfd);
	else if (data->aux_tkn->type == HERE_DOC_RED)
		ft_here_doc_redir(data, infd);
}
