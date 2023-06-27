/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:48:29 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/18 18:55:13 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printptr(void *ptr)
{
	int	p_len;

	p_len = 0;
	p_len += write(1, "0x", 2);
	p_len += ft_printhex((unsigned long)ptr, 'x');
	return (p_len);
}
