/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_to_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:33:33 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 23:36:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_arg_to_cmd(t_cmd *cmd, const char *arg)
{
	int (i) = 0;
	while (i < MAX_ARGS && cmd->args[i] != NULL)
		i++;
	if (i < MAX_ARGS)
	{
		cmd->args[i] = ft_strdup(arg);
		if (cmd->args[i] == NULL)
		{
			write(STDERR, "Error: Memory allocation failed\n", 32);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(STDERR, "Error: Too many arguments\n", 27);
		exit(EXIT_FAILURE);
	}
}
