/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:46:38 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 18:56:08 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_output_redir(t_data *data, int *outfd, int is_ap)
{
	int		fd;
	char	**aux;
	char	*aux_str;

	aux_str = data->aux_tkn->string + 1;
	aux = ft_split(aux_str, ' ');
	if (!aux[0] || aux == NULL)
	{
		ft_free_str_array(aux);
		ft_putstr_fd("Conchita: redirect syntax error\n", 2);
		return ;
	}
	if (is_ap == 1)
		fd = open(aux[0], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd = open(aux[0], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_free_str_array(aux);
	if (*outfd != STDOUT_FILENO)
		close(*outfd);
	*outfd = fd;
}
