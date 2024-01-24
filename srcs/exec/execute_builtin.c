/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:20:24 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/24 23:43:53 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	execute_builtin(t_commands *cmds, char **envp, int last_exit_status)
{
	if (ft_strcmp(cmds->cmds[0], "cd") == 0)
        return (builtin_cd(cmds->cmds, envp));
    else if (ft_strcmp(cmds->cmds[0], "echo") == 0)
        return builtin_echo(cmds->cmds);
    else if (ft_strcmp(cmds->cmds[0], "env") == 0)
        return builtin_env(envp);
    else if (ft_strcmp(cmds->cmds[0], "exit") == 0)
        return builtin_exit(cmds->cmds, last_exit_status);
    else if (ft_strcmp(cmds->cmds[0], "export") == 0)
        return (builtin_export(cmds->cmds, envp));
    else if (ft_strcmp(cmds->cmds[0], "pwd") == 0)
        return builtin_pwd();
    else if (ft_strcmp(cmds->cmds[0], "unset") == 0)
        return (builtin_unset(cmds->cmds, envp));
    else
        return (-1);
}
