/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:25:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/13 13:41:59 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_redir(t_data *data, int infd, int outfd)
{
	if (data->aux_tkn->type == IN_RED)
		ft_input_redir(data, infd);
	else if (data->aux_tkn->type == OUT_RED)
		ft_output_redir(data, outfd);
	else if (data->aux_tkn->type == APPEND_RED)
		ft_append_redir(data, outfd);
	else if (data->aux_tkn->type == HERE_DOC_RED)
		ft_here_doc_redir(data, infd);
}

void	ft_input_redir(t_data *data, int infd)
{
	(void)data;
	(void)infd;
}

void	ft_output_redir(t_data *data, int outfd)
{
	(void)data;
	(void)outfd;

}

void	ft_append_redir(t_data *data, int outfd)
{
	(void)data;
	(void)outfd;

}

void	ft_here_doc_redir(t_data *data, int infd)
{
	(void)data;
	(void)infd;

}
