/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:29:36 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 14:34:23 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute(t_commands *cmds, char **envp, int last_exit_status)
{
	int			i;
	int			builtin_status;
	char		**av;
	t_commands tmp_cmds;

	i = 0;
	while (cmds->cmds[i] != NULL)
	{
		av = ft_split(cmds->cmds[i], ' ');
		if (av && av[0])
		{
			tmp_cmds.cmds = av;
			builtin_status = execute_builtin(&tmp_cmds, envp, last_exit_status);
			if (builtin_status == -1)
				execute_external(&tmp_cmds, envp);
		}
		if (av)
			free(av);
		i++;
	}
}
