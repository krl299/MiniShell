/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:22:49 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/09/26 18:49:19 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	words_n(char const *s, char c)
{
	int	i;
	int	cnt;
	int	wrd;

	cnt = 0;
	i = 0;
	wrd = 0;
	while (s[i])
	{
		if (s[i] != c && wrd == 0)
		{
			wrd = 1;
			cnt += 1;
		}
		else if (s[i] == c)
			wrd = 0;
		i++;
	}
	return (cnt);
}

static int	wrd_len(char *s, int *i, char c)
{
	int	x;
	int	i2;

	x = 0;
	while (s[*i] == c && s[*i])
		*i += 1;
	i2 = *i;
	while (s[i2] && s[i2] != c)
	{
		i2++;
		x++;
	}
	return (x);
}

static int	wrt_words(char *s, char **p, int *i, char c)
{
	int		wrd_sz;
	int		j;
	int		ip;
	char	*pw;

	wrd_sz = wrd_len(s, i, c);
	ip = 0;
	while (wrd_sz != 0)
	{
		pw = (char *)ft_calloc(sizeof(char), (wrd_sz + 1));
		if (!pw)
			return (1);
		j = 0;
		while (j < wrd_sz)
		{
			pw[j++] = s[*i];
			*i += 1;
		}
		pw[j] = '\0';
		p[ip] = pw;
		ip++;
		wrd_sz = wrd_len(s, i, c);
	}
	p[ip] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		error;
	char	**res;

	if (!s)
		return (NULL);
	count = words_n(s, c);
	res = (char **)ft_calloc(sizeof(char *), count + 1);
	if (!res)
		return (NULL);
	i = 0;
	error = wrt_words((char *)s, res, &i, c);
	if (error)
	{
		i = 0;
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (NULL);
	}
	return (res);
}
