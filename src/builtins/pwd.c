/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:16:20 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/14 01:35:35 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_built_pwd(int fd)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		perror("pwd");
	else
	{
		ft_putstr_fd(cwd, fd);
		ft_putstr_fd("\n", fd);
	}
	free(cwd);
}
