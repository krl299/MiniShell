/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:36:42 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/27 19:47:37 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_token_list(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tokens)
	{
		tmp = tokens->next;
        free(tokens->string);
        free(tokens);
        tokens = tmp;
    }
}

void    ft_clean_tokens(t_data *data)
{
    t_token *tmp;

    tmp = data->tokens;
    free(data->linebuffer);
    ft_clean_token_list(tmp);
    data->tokens = NULL;
}
