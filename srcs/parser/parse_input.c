/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:44:39 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/24 23:16:55 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_input(t_data *data)
{
	t_commands	*cmds;
	char		**parsed_cmds;

	init_commands(data, &cmds);
	parsed_cmds = tokenize_input(data->user_input, cmds);
	if (!parsed_cmds)
	{
		ft_putstr_fd("Error: Failed to tokenize input", STDERR);
		g_status_code = 1;
		return ;
	}
	if (!convert_tokens_to_cmds(&cmds, parsed_cmds))
	{
		ft_putstr_fd("Error: Failed to convert tokens to cmds", STDERR);
		g_status_code = 1;
		return ;
	}
	parse_and_execute_cmds(&cmds);
	free_cmds(&cmds);
	free_str(parsed_cmds);
}
