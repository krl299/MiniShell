/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:46:02 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/18 18:35:26 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_input_redir(t_data *data, int *infd)
{
	int		new_infd;
	char	**tmp;
	char	*tmp_str;

	tmp_str = data->aux_tkn->string + 1;
	tmp = ft_split(tmp_str, ' ');
	if (tmp == NULL || !tmp[0])
	{
		ft_free_str_array(tmp);
		ft_putstr_fd("Conchita: redirect syntax error\n", 2);
		return ;
	}
	new_infd = open(tmp[0], O_RDONLY);
	ft_free_str_array(tmp);
	if (new_infd == -1)
	{
		perror("open: ");
		return ;
	}
	if (*infd != STDIN_FILENO)
		close(*infd);
	*infd = new_infd;
}
