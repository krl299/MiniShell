/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:25:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 18:02:21 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_redir(t_data *data, int infd, int outfd)
{
	t_token	*tmp;

	tmp = data->aux_tkn;
	if (data->aux_tkn->type == IN_RED)
		ft_input_redir(data, &infd);
	else if (data->aux_tkn->type == OUT_RED)
		ft_output_redir(data, &outfd, 0);
	else if (data->aux_tkn->type == APPEND_RED)
		ft_output_redir(data, &outfd, 1);
	else if (data->aux_tkn->type == HERE_DOC_RED)
		ft_here_doc_redir(data, &infd);
	if (tmp->next && (tmp->next->type == OUT_RED
			|| tmp->next->next->type == APPEND_RED || tmp->next->type == IN_RED
			|| tmp->next->type == HERE_DOC_RED))
	{
		data->aux_tkn = tmp->next;
		ft_redir(data, infd, outfd);
	}
	else
		ft_process_commands(data, infd, outfd);
}
