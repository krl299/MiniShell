/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:36:26 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 15:41:36 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECCTIONS_H
# define REDIRECCTIONS_H
# include "parser.h"

void	ft_redir(t_data *data, int infd, int outfd);

void	ft_input_redir(t_data *data, int *infd);

void	ft_output_redir(t_data *data, int outfd);

void	ft_append_redir(t_data *data, int outfd);

void	ft_here_doc_redir(t_data *data, int *infd);

#endif
