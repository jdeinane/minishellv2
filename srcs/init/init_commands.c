/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:39:56 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 17:41:37 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_commands	*init_commands(void)
{
	t_commands	*cmds;

	cmds = malloc(sizeof(t_commands));
	if (!cmds)
		return (NULL);
	cmds->pid = NULL;
	cmds->num_cmds = 0;
	cmds->num_exec = 0;
	cmds->operators = NULL;
	cmds->exit_value = 0;
	cmds->tokens = NULL;
	cmds->paths = NULL;
	cmds->pipe = NULL;
	cmds->io = NULL;
	cmds->cmd = NULL;
	return (cmds);
}
