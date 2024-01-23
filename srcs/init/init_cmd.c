/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:49:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 21:56:10 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	cmd->path = NULL;
	cmd->args = malloc(sizeof(char *) * (MAX_ARGS + 1));
	if (!cmd->args)
		return ;
	while (i <= MAX_ARGS)
	{
		cmd->args[i] = NULL;
		i++;
	}
	cmd->redirections = malloc(sizeof(char*) * MAX_REDIRECTIONS);
	if (!cmd->redirections)
	{
		free(cmd->args);
		return ;
	}
	i = 0;
	while (i < MAX_REDIRECTIONS)
		cmd->redirections[i++] = NULL;
}
