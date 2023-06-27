/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:41:28 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/18 18:54:35 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_num_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*strn;
	int		len;

	len = ft_num_len(n);
	strn = (char *)malloc(sizeof(char) * len + 1);
	if (!strn)
		return (0);
	strn[len] = '\0';
	while (n != 0)
	{
		strn[--len] = n % 10 + 48;
		n /= 10;
	}
	return (strn);
}

int	ft_printnbr_unsigned(unsigned int n)
{
	int		nbrlen;
	char	*strn;

	nbrlen = 0;
	if (n == 0)
		nbrlen += write(1, "0", 1);
	else
	{
		strn = ft_uitoa(n);
		nbrlen += ft_printstr(strn);
		free(strn);
	}
	return (nbrlen);
}
