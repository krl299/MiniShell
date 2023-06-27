/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:37:04 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/09/22 17:28:47 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_d;
	unsigned int	len_s;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	i = len_d;
	j = 0;
	if (size < 1)
		return (len_s + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < len_d)
		return (len_s + size);
	else
		return (len_d + len_s);
}
