/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:34:11 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/09/22 16:27:25 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	unsigned char	*b;
	size_t			i;

	b = block;
	i = 0;
	while (i < size)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}
