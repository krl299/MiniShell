/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:21:08 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/29 12:59:28 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
void	ft_built_unset();
//
void	ft_built_env();
//
void	ft_built_exit();
