/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:26:46 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/05 19:38:49 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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
	int		id_last_proc;
	char	**argv;
	char	**envp;
	char	*linebuffer;
	t_token	*tokens;
}	t_data;

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

// PARSER_ENV.C
int	ft_replace_var(t_token *input, t_data *data);

// CLEANER.C
void	ft_clean_tokens(t_data *data);
#endif
