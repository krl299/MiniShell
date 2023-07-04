/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:11:31 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/04 20:36:32 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_empty_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_is_inter(char *str)
{
	int len;
	
	len = ft_strlen(str);
	if (len == 2 && str[0] == '$' && str[1] == '?') {
        return 1;
    }
    return 0;
}
