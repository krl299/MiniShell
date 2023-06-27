/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:45:18 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/09/22 16:26:20 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *block, size_t size)
{
	unsigned char	*b;
	size_t			i;

	b = (unsigned char *)block;
	i = 0;
	while (i < size)
	{
		b[i] = 0;
		i++;
	}
}
