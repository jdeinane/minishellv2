/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:11:31 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 17:47:28 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	free_cmd(t_commands *cmds)
{
	int (i) = 0;
	int (j);
	while (i < cmds->num_exec)
	{
		j = 0;
		while (cmds->cmd[i].args[j] != NULL)
			free(cmds->cmd[i].args[j++]);
		free(cmds->cmd[i].args[j]);
		free(cmds->cmd[i].args);
		j = 0;
		while (cmds->cmd[i].redirections[j] != NULL)
			free(cmds->cmd[i].redirections[j++]);
		free(cmds->cmd[i].redirections[j]);
		free(cmds->cmd[i].redirections);
		free(cmds->cmd[i].path);
		i++;
	}
	free_io(cmds->io);
	free(cmds->cmd);
}

void	free_io(t_redirect *io)
{
	if (!io)
		return ;
	restore_io(io);
	if (io->heredoc_eof)
	{
		unlink(io->in_file);
		free_ptr(io->heredoc_eof);
	}
	else if (io->in_file)
		free_ptr(io->in_file);
	else if (io->out_file)
		free_ptr(io->out_file);
	free_ptr(io);
}

void	free_cmds(t_commands *cmds)
{
	int (i) = 0;
	if (cmds->cmds != NULL)
	{
		free_cmd(cmds);
		free_pipes(cmds);
		while (cmds->cmds[i] != NULL)
			free(cmds->cmds[i++]);
		free(cmds->cmds[i]);
		free(cmds->cmds);
		i = 0;
		if (cmds->paths != NULL)
		{
			while (cmds->paths[i] != NULL)
				free(cmds->paths[i++]);
			free(cmds->paths[i]);
		}
		free(cmds->paths);
		free(cmds->operators);
		free(cmds->pid);
	}
	free(cmds);
}

void	close_fds(t_commands *cmds, bool reset_io)
{
	if (cmds->io)
	{
		if (cmds->io->fd_in != -1)
			close(cmds->io->fd_in);
		if (cmds->io->fd_out != -1)
			close(cmds->io->fd_out);
		if (reset_io == true)
			restore_io(cmds->io);
	}
	close_pipes(cmds);
}

void	free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i])
			{
				free_ptr(str[i]);
				str[i] = NULL;
			}
			i++;
		}
		free(str);
		str = NULL;
	}
}

bool	clear_prev_input(t_redirect *io, bool in_file)
{
	if (in_file == true && io->in_file)
	{
		if (io->fd_in == -1 || (io->out_file && io->fd_out == -1))
			return (false);
		if (io->heredoc_eof != NULL)
		{
			free_ptr(io->heredoc_eof);
			io->heredoc_eof = NULL;
			unlink(io->in_file);
		}
		free_ptr(io->in_file);
		close(io->fd_in);
	}
	else if (in_file == false && io->out_file)
	{
		if (io->fd_out == -1 || (io->in_file && io->fd_in == -1))
			return (false);
		free_ptr(io->out_file);
		close(io->fd_out);
	}
	return (true);
}

void	free_data(t_data *data, bool exit_shell)
{
	if (data)
	{
		if (data->user_input)
			free_ptr(data->user_input);
		if (exit_shell)
		{
			if (data->old_work_dir)
				free_ptr(data->old_work_dir);
			if (data->work_dir)
				free_ptr(data->work_dir);
			if (data->env)
				free_str(data->env);
			rl_clear_history();
		}
	}
}

void	free_pipes(t_commands *cmds)
{
	int	i;

	i = 0;
	if (cmds->pipe)
	{
		while (i < cmds->num_exec)
		{
			if (cmds->pipe[i].fd)
				free(cmds->pipe[i].fd);
			i++;
		}
		free(cmds->pipe);
	}
}
