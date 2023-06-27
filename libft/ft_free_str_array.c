/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:21:43 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/04 19:57:17 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str_array(char **array)
{
	char	**aux;
	int		i;

	if (array == NULL)
		return ;
	aux = array;
	i = 0;
	while (aux[i])
	{
		free(aux[i]);
		i++;
	}
	free(aux);
}
