/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:44:39 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 17:17:21 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_commands	*parse_input(t_data *data)
{
	t_commands	*cmds;
	char		**parsed_cmds;

	cmds = malloc(sizeof(t_commands));
	if (cmds == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory", STDERR);
		g_status_code = 1;
		return (NULL);
	}
	init_commands(data, cmds);
	parsed_cmds = tokenize_input(data->user_input, cmds);
	if (!parsed_cmds)
	{
		ft_putstr_fd("Error: Failed to tokenize input", STDERR);
		g_status_code = 1;
		free(cmds);
		return (NULL);
	}
	if (!convert_tokens_to_cmds(cmds, parsed_cmds))
	{
		ft_putstr_fd("Error: Failed to convert tokens to cmds", STDERR);
		g_status_code = 1;
		free_cmds(cmds);
		free_str(parsed_cmds);
		return (NULL);
	}
	free_str(parsed_cmds);
	return (cmds);
}
