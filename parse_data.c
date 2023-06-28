/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:40:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/28 20:14:56 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_skip_spaces(const char *linebuffer, int *cur)
{
	while (linebuffer[*cur] && linebuffer[*cur] == ' ')
		(*cur)++;
}

void	ft_process_special_chars(t_data *data, int *i, int *cur)
{
	if (data->linebuffer[*cur] == '\'')
		ft_process_quotes(data, i, cur, '\'');
	else if (data->linebuffer[*cur] == '\"')
		ft_process_quotes(data, i, cur, '\"');
	else if (ft_strchr("|><", data->linebuffer[*cur]))
		ft_symbol_token(data, i, cur, data->linebuffer[*cur]);
}

void	ft_process_regular_chars(t_data *data, int *i, int *cur)
{
	while (data->linebuffer[*cur] && data->linebuffer[*cur] != '\''
		&& data->linebuffer[*cur] != '\"'
		&& ft_strchr("|><", data->linebuffer[*cur]) == 0)
	{
		if (data->linebuffer[*cur] == ' ')
		{
			ft_add_token(data, *i, *cur);
			while (data->linebuffer[*cur]
				&& data->linebuffer[*cur] == ' ')
				(*cur)++;
			*i = *cur;
		}
		(*cur)++;
	}
	ft_add_token(data, *i, *cur);
}

void	ft_trim_spaces(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ')
		i--;
	str[i + 1] = '\0';
}

void	ft_parse_data(t_data *data)
{
	int	cur;
	int	i;

	cur = 0;
	ft_trim_spaces(data->linebuffer);
	while (data->linebuffer[cur])
	{
		i = cur;
		ft_skip_spaces(data->linebuffer, &cur);
		ft_process_special_chars(data, &i, &cur);
		ft_process_regular_chars(data, &i, &cur);
	}
	ft_set_tokens_type(data);
}
