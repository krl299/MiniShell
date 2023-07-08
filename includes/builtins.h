/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:21:08 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/08 19:09:20 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "parser.h"

//Get the token type builting and identify what need to do.
void	ft_built(t_data *data);
//Get the current working directory and prints it to stdout.
//If an error occurs, it prints the error to stderr.
void	ft_built_pwd(void);
//
void	ft_built_echo(char **input);
//
void	ft_built_cd();
//
void	ft_built_export();
//
void	ft_built_unset(t_data *data);
//
void	ft_built_env(t_data *data);
//
void	ft_built_exit();

#endif
