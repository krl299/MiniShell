/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:21:08 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 18:49:24 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "parser.h"

//Get the token type builting and identify what need to do.
void	ft_built(t_data *data, int fd);
//Get the current working directory and prints it to stdout.
//If an error occurs, it prints the error to stderr.
void	ft_built_pwd(int fd);
//
int		ft_is_n(char *str);
void	ft_built_echo(t_token *token, int fd);
//
void	ft_built_cd(t_data *data);
//
void	ft_built_export(t_data *data);
//
void	ft_built_unset(t_data *data);
//
void	ft_built_env(t_data *data);
//
void	ft_built_exit(t_data *data);

#endif
