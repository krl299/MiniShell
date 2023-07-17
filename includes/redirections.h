/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:36:26 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/07/17 17:32:28 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H
# include "parser.h"

void	ft_redir(t_data *data, int infd, int outfd);

void	ft_input_redir(t_data *data, int *infd);

void	ft_output_redir(t_data *data, int *outfd, int is_ap);

void	ft_append_redir(t_data *data, int outfd);

void	ft_here_doc_redir(t_data *data, int *infd);

#endif
