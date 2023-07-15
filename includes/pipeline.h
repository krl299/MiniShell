/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:56:04 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/07/14 18:50:08 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

// PROCESSOR.C
void	ft_process_commands(t_data *data, int infd, int outfd);

// PROCESSOR_UTILS.C
void	ft_replace_path(t_data *data);

#endif
