/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:29:36 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 17:07:15 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	execute_command(t_commands *cmds, char **envp)
{
	int			status;
	int			last_exit_status;
	int			i;
	char		*cmd_args;

	i = 0;
	status = 0;
	while (i < cmds->num_cmds)
	{
		cmd_args = cmds->cmds[i];
		last_exit_status = 0;
		status = execute_builtin(cmds, envp, last_exit_status);
		if (status == -1)
			status = execute_external(cmds, envp);
		i++;
	}
	return (status);
}

int	execute(t_data *data)
{
	int			status;
	t_commands	*cmds;

	if (data == NULL || data->user_input == NULL)
		return (-1);
	cmds = parse_input(data);
	if (cmds == NULL)
		return (-1);
	status = execute_command(cmds, data->env);
	free_cmds(cmds);
	return (status);
}
