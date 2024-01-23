/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:31:22 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 18:40:02 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_pipes(t_commands *cmds, int index)
{
	if (index == 0)
		check_pipes(cmds, index);
	else
	{
		if (cmds->operators[index])
			check_pipes(cmds, index);
		if (cmds->operators[index - 1] == '|')
			dup2(cmds->pipe[index].fd[0], STDIN);
	}
	close_pipes(cmds);
}
