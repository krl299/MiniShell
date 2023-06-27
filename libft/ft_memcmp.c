/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:48:04 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/09/22 17:02:43 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1p;
	const unsigned char	*s2p;

	s1p = (const unsigned char *)str1;
	s2p = (const unsigned char *)str2;
	while (n-- > 0)
	{
		if (*s1p != *s2p)
			return (*s1p - *s2p);
		s1p++;
		s2p++;
	}
	return (0);
}
