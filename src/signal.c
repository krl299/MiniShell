/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:00:45 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/18 13:56:23 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	*g_ptr_fork;

static int	ft_get_is_fork(void)
{
	int	is_fork;

	is_fork = *g_ptr_fork;
	return (is_fork);
}

static void	ft_sigint_handler()
{
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	if (ft_get_is_fork() == 0)
		rl_redisplay();
}

void	ft_set_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sigint_handler);
}

void	ft_is_fork(int i)
{
	static int	is_fork;

	is_fork = i;
	g_ptr_fork = &is_fork;
}
