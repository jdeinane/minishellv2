/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:44:39 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 21:48:36 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_commands(t_commands *cmds, t_tokenizer *tokenizer)
{
	int		i;
	t_cmd	current_cmd;
	char	*token;

	i = 0;
	init_cmd(&current_cmd);
	while (i < tokenizer->count)
	{
		token = get_token(tokenizer, i);
		if (is_operator(token))
		{
			add_cmd_to_cmds(cmds, &current_cmd);
			init_cmd(&current_cmd);
			handle_operators(cmds, token);
		}
		else if (is_redirection(token))
			handle_redirection(&current_cmd, get_token(tokenizer, ++i));
		else
			add_arg_to_cmd(&current_cmd, token);
		i++;
	}
	if (current_cmd.args[0] != NULL)
		add_cmd_to_cmds(cmds, &current_cmd);
}

