/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:42:13 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/26 20:03:12 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_token(t_data *data, int i, int cur)
{
	t_token	*new;
	t_token	*tmp;
	char	*str;

	str = ft_substr(data->linebuffer, i, cur - i);
	new = malloc(sizeof(t_token));
	if (!new)
		return ;
	new->string = str;
	new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	if (!data->tokens)
		data->tokens = new;
	else
	{
		tmp = data->tokens;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}

void    ft_process_quotes(t_data *data, int *iter, int *curr, char quote)
{
    int cur;
	int	i;

	cur = *curr;
	i = *iter;
	cur++;
	while (data->linebuffer[cur] && data->linebuffer[cur] != quote)
		cur++;
	if (data->linebuffer[cur] == quote)
		cur++;
	ft_add_token(data, i, cur);
	*curr = cur;
}

void    ft_parse_data(t_data *data)
{
    int cur;
    int i;

    cur = 0;
    while (data->linebuffer[i])
    {
        i = cur;
        if (data->linebuffer[i] == '\'')
            ft_process_quotes(data, &i, &cur, '\'');
        else if (data->linebuffer[i] == '\"')
            ft_process_quotes(data, &i, &cur, '\"');
        else
        {
            // TODO
        }
    }
}

void    ft_create_tokens(t_data *data)
{
    ft_parse_data(data);
}