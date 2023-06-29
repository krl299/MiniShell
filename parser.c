/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:42:13 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/27 17:43:02 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print the tokens from the data structure with a string / type format
void	ft_print_tokens(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		printf("string: %s\n", tmp->string);
		printf("type: %d\n", tmp->type);
		tmp = tmp->next;
	}
}

void	ft_create_tokens(t_data *data)
{
	ft_parse_data(data);
}
