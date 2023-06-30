/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:34:23 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/30 18:26:18 by jmatas-p         ###   ########.fr       */
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
# include "libft/libft.h"

enum e_datatype
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	PIPE,
	BUILTINS,
	ENVI_VAR,
	IN_RED,
	OUT_RED,
	APPEND_RED,
	HERE_DOC_RED
};

typedef struct s_token
{
	char			*string;
	enum e_datatype	type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	*linebuffer;
	t_token	*tokens;
}	t_data;

//	SIGNAL.C
void	ft_set_signal(void);

//	UTILS.C
int		ft_empty_line(const char *str);

// INIT_DATA.C
void	ft_init_data(t_data *data, int argc, char **argv, char **envp);

// PARSER.C
void	ft_print_tokens(t_data *data);
int		ft_is_builtin(char *str);
void	ft_create_tokens(t_data *data);

// PARSER_FIXER.C
void	ft_fix_blanks_in_tokens(t_data *data);
void	ft_set_builtins(t_data *data);
void	ft_delete_quotes(t_data *data);
void	ft_set_env_variables(t_data *data);

// PARSE_DATA.C
void	ft_parse_data(t_data *data);

// CLEANER.C
void	ft_clean_tokens(t_data *data);

#endif
