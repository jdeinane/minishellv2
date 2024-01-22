/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:55:43 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 00:17:29 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_status_code;

void	handle_quotes(t_tokenizer *tokenizer)
{
	char (quote_type) = current_char(tokenizer);
	int (start_index) = tokenizer->start - tokenizer->input + 1;
	int (token_len) = 0;
	advance_tokenizer(tokenizer);
	while (more_tokens_available(tokenizer) &&
			current_char(tokenizer) != quote_type)
	{
		advance_tokenizer(tokenizer);
		token_len++;
	}
	if (more_tokens_available(tokenizer) &&
			current_char(tokenizer) == quote_type)
	{
		add_token(tokenizer);
		advance_tokenizer(tokenizer);
	}
	else
	{
		write(STDERR_FILENO, "Error: Unmatched quote\n", 24);
		g_status_code = 2;
		tokenizer->error = true;
		return ;
	}
}