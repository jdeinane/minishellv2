/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:14:38 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/22 23:54:27 by jubaldo          ###   ########.fr       */
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

	tokenizer = init_tokenizer(input);
	while (more_tokens_available(tokenizer))
	{
		if (is_space(current_char(tokenizer)))
			handle_whitespace(tokenizer);
		else if (is_quote(current_char(tokenizer)))
			handle_quotes(tokenizer);
		else if (is_operator(current_char(tokenizer)))
			handle_operators(tokenizer, cmds);
		else if (is_env_var(current_char(tokenizer)))
			handle_env_variables(tokenizer);
		else
			handle_regular_chars(tokenizer);
		advance_tokenizer(tokenizer);
	}
	tokens = convert_tokens_to_cmds(tokenizer);
	free_tokenizer(tokenizer);
}
