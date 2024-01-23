/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:44:39 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 23:32:35 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_commands(t_commands *cmds, t_tokenizer *tokenizer)
{
	int		i;
	t_cmd	*current_cmd;
	char	*token;
	char	*expanded_value;

	i = 0;
	init_cmd(&current_cmd);
	while (i < tokenizer->count)
	{
		token = get_token(tokenizer, i);
		if (is_command(token, i))
			current_cmd->path = ft_strdup(token);
		else if (is_argument(token, i, cmds))
			add_arg_to_cmd(&current_cmd, token);
		else if (is_redirection(token))
			handle_redirections(current_cmd, get_token(tokenizer, ++i));
		else if (is_pipe(token))
		{
			add_cmd_to_cmds(cmds, &current_cmd);
			init_cmd(&current_cmd);
		}
		else if (is_env_var(token))
		{
			expanded_value = expand_env_var(token);
			add_arg_to_cmd(&current_cmd, expanded_value);
			free(expanded_value);
		}
		i++;
	}
	add_cmd_to_cmds(cmds, &current_cmd);
}
