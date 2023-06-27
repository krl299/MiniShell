/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:29:29 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/18 18:53:47 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_processformat(const char c, va_list argl)
{
	int	total_len;

	total_len = 0;
	if (c == '%')
		total_len += ft_printprct();
	else if (c == 'p')
		total_len += ft_printptr(va_arg(argl, void *));
	else if (c == 'c')
		total_len += ft_printchar(va_arg(argl, int));
	else if (c == 's')
		total_len += ft_printstr(va_arg(argl, char *));
	else if (c == 'u')
		total_len += ft_printnbr_unsigned(va_arg(argl, unsigned int));
	else if (c == 'x' || c == 'X')
		total_len += ft_printhex(va_arg(argl, unsigned int), c);
	else if (c == 'd' || c == 'i')
		total_len += ft_printnbr(va_arg(argl, int));
	return (total_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	argl;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(argl, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_processformat(str[i + 1], argl);
			i++;
		}
		else
		{
			len += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(argl);
	return (len);
}
