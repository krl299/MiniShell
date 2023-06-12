/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:33:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/06/12 14:18:45 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	//ignore Ctrl-\ Ctrl-C signals
	
	while(1)
	{
		//keep getline in a loop in case interruption occurs
		//userpressed CTRL-D to exit
		//lexically analyze and build a list o tokens
		///parse the tokens into an abstract syntax tree
		///free the structures
	}
	return (0);
}
