/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:34:23 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/18 13:59:45 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "builtins.h"
# include "parser.h"
# include "pipeline.h"
# include "redirections.h"

//	SIGNAL.C
void	ft_set_signal(void);
void	ft_is_fork(int i);

//	UTILS.C
int		ft_empty_line(const char *str);
int     ft_is_inter(char *str);

// MINISHELL.C
void	ft_command(t_data *data, int infd, int outfd);

#endif
