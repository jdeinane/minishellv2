/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:39:56 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 18:09:27 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_commands(t_data *data, t_commands *cmds)
{
	int		i;
	char	*new_input;

	new_input = trim_input(data->user_input);
	cmds->cmds = tokenize_input(new_input, cmds);
	free(new_input);
	i = 0;
	if (cmds->exit_value == 0)
	{
		while (cmds->cmds[i])
			i++;
		cmds->num_cmds = i;
		cmds->paths = get_paths(data->env);
		if (cmds->num_cmds > 0)
			handle_operators(data, cmds);
		init_pipe(cmds);
		cmds->pid = (pid_t *)ft_calloc(sizeof(pid_t), cmds->num_cmds + 1);
		cmds->cmd = ft_calloc(cmds->num_cmds, sizeof(t_cmd));
	}
}
