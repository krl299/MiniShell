/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:54:00 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/10/03 19:01:13 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*strt;

	if (!lst || !del)
		return ;
	strt = *lst;
	while (strt)
	{
		tmp = strt->next;
		del(strt->content);
		free(strt);
		strt = tmp;
	}
	*lst = NULL;
}
