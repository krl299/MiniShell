/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:28:05 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/09/26 19:31:13 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		new_string = malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (new_string == NULL)
			return (NULL);
		while (i < ft_strlen(s))
		{
			new_string[i] = f((unsigned int)i, s[i]);
			i++;
		}
		new_string[i] = 0;
		return (new_string);
	}
	return (NULL);
}
