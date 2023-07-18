/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:25:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/18 18:34:51 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//function that checks if the redirection is valid
// receives the redirection token and detects if it's string value is valid 
// (has a word after the redirection symbol)
// returns 1 if it's valid, 0 if it's not
int	ft_is_valid_redir(t_token *tkn)
{
	if (!ft_strcmp(tkn->string, ">") || !ft_strcmp(tkn->string, ">>")
		|| !ft_strcmp(tkn->string, "<") || !ft_strcmp(tkn->string, "<<"))
		return (0);
	else
		return (1);
}

void	ft_redir(t_data *data, int infd, int outfd)
{
	t_token	*tmp;

	tmp = data->aux_tkn;
	if (!ft_is_valid_redir(tmp))
	{
		ft_putstr_fd("Conchita: redirect syntax error\n", 2);
		return ;
	}
	if (data->aux_tkn->type == IN_RED)
		ft_input_redir(data, &infd);
	else if (data->aux_tkn->type == OUT_RED)
		ft_output_redir(data, &outfd, 0);
	else if (data->aux_tkn->type == APPEND_RED)
		ft_output_redir(data, &outfd, 1);
	else if (data->aux_tkn->type == HERE_DOC_RED)
		ft_here_doc_redir(data, &infd);
	if (tmp->next && (tmp->next->type == OUT_RED
			|| tmp->next->type == APPEND_RED || tmp->next->type == IN_RED
			|| tmp->next->type == HERE_DOC_RED))
	{
		data->aux_tkn = tmp->next;
		ft_redir(data, infd, outfd);
	}
	else
		ft_process_commands(data, infd, outfd);
}
