/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:14:38 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 15:52:19 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	more_tokens_available(const t_tokenizer *tokenizer)
{
	return (*(tokenizer->start) != '\0');
}

char	current_char(const t_tokenizer *tokenizer)
{
	return (*(tokenizer->start));
}

void	advance_tokenizer(t_tokenizer *tokenizer)
{
	if (*(tokenizer->start) != '\0')
		tokenizer->start++;
}

char	**tokenize_input(const char *input, t_commands *cmds)
{
	t_tokenizer	*tokenizer;
	char		**parsed_cmds;
	char		**tokens;

	tokens = NULL;
	tokenizer = init_tokenizer(input);
	while (more_tokens_available(tokenizer) && !tokenizer->error)
	{
		if (is_space(current_char(tokenizer)))
			handle_whitespace(tokenizer);
		else if (is_quote(current_char(tokenizer)))
			handle_quotes(tokenizer);
		else if (is_operator(current_char(tokenizer)))
			handle_operators(tokenizer);
		else if (is_env_var(current_char(tokenizer)))
			handle_env_variables(tokenizer);
		else
			handle_regular_chars(tokenizer);
		advance_tokenizer(tokenizer);
	}
	if (!tokenizer->error)
	{
		parsed_cmds = get_parsed_cmds_from_tokens(tokenizer);
		if (convert_tokens_to_cmds(cmds, parsed_cmds))
			tokens = cmds->cmds;
		else
		{
			tokens = NULL;
			g_status_code = 1;
		}
		free_parsed_cmds(parsed_cmds);
	}
	else
	{
		g_status_code = 1;
		tokens = NULL;
	}
	free_tokenizer(tokenizer);
	return (tokens);
}
