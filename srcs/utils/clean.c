/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:11:31 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 16:22:19 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
