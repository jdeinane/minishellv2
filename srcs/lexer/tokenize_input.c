/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:14:38 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 11:21:37 by jubaldo          ###   ########.fr       */
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
		tokens = convert_tokens_to_cmds(tokenizer);
	else
		g_status_code = 1;
	free_tokenizer(tokenizer);
	return (tokens);
}
