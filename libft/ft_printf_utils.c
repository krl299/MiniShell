/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:33:24 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/18 18:54:07 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		len += ft_printnbr(nb / 10);
		len += ft_printnbr(nb % 10);
	}
	if (nb < 10)
		len += ft_putchar(nb + 48);
	return (len);
}

int	ft_printprct(void)
{
	write(1, "%", 1);
	return (1);
}
