/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:46:02 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/15 19:57:09 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_input_redir(t_data *data, int infd)
{
	//int		new_infd;
	(void)infd;
	char	**tmp;

	tmp = ft_split(data->tokens->string, ' ');
	int i = -1;
	while (tmp[++i])
		printf("%s\n", tmp[i]);
	
}
