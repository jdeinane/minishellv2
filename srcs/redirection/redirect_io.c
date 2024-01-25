/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:54:00 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 17:28:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	redirect_io(t_redirect *io, int index_cmd)
{
	if (!io || io->cmd_index != index_cmd)
		return ;
	io->stdin_backup = dup(STDIN_FILENO);
	if (io->stdin_backup == -1)
	{
		perror("dup");
		return ;
	}
	io->stdout_backup = dup(STDOUT_FILENO);
	if (io->stdout_backup == -1)
	{
		return ;
		perror("dup");
	}
	if(io->fd_in != -1)
	{
		if (dup2(io->fd_in, STDIN_FILENO) == -1)
		{
			perror("dup2");
			return ;
		}
	}
	if (io->fd_out != -1)
	{
		if (dup2(io->fd_out, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			return ;
		}
	}
}

void	restore_io(t_redirect *io)
{
	if (io->stdin_backup != -1)
	{
		if (dup2(io->stdin_backup, STDIN_FILENO) == -1)
			return ;
		close(io->stdin_backup);
		io->stdin_backup = -1;
	}
	if (io->stdout_backup != -1)
	{
		if (dup2(io->stdout_backup, STDOUT_FILENO) == -1)
			return ;
		close(io->stdout_backup);
		io->stdout_backup = -1;
	}
}

bool	check_file(t_redirect *io, t_commands *cmds, bool free)
{
	if (!io || (!io->in_file && !io->out_file))
		return (true);
	if ((io->in_file && io->fd_in == -1) || ((io->out_file && io->fd_out == -1)
		&& io->error == true))
	{
		if (free)
		{
			close_fds(cmds, false);
			free_cmds(cmds);
		}
		return (false);
	}
	return (true);
}
