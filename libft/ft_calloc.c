/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:54:20 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/09/22 17:41:28 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;

	res = malloc(nitems * size);
	if (res == NULL)
		return (res);
	ft_bzero(res, nitems * size);
	return (res);
}
