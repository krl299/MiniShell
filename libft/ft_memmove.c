/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:07:10 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/09/22 16:59:05 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	if (!str1 && !str2)
		return (0);
	if (str1 > str2)
	{
		dp = str1 + n;
		sp = str2 + n;
		while (n-- > 0)
			*--dp = *--sp;
	}
	else
	{
		dp = str1;
		sp = str2;
		while (n-- > 0)
			*dp++ = *sp++;
	}
	return (str1);
}
