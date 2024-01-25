/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:45:09 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 14:46:28 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	next_char(const t_tokenizer *tokenizer)
{
	if (*(tokenizer->start + 1) != '\0')
		return (*(tokenizer->start + 1));
	return ('\0');
}

void	handle_operators(t_tokenizer *tokenizer)
{
	if (current_char(tokenizer) == '|')
	{
		add_token(tokenizer, "|", 1);
		advance_tokenizer(tokenizer);
	}
	else if (current_char(tokenizer) == '>')
	{
		if (next_char(tokenizer) == '>')
		{
			add_token(tokenizer, ">>", 2);
			advance_tokenizer(tokenizer);
		}
		add_token(tokenizer, ">", 1);
		advance_tokenizer(tokenizer);
	}
	else if (current_char(tokenizer) == '<')
	{
		if (next_char(tokenizer) == '<')
		{
			add_token(tokenizer, "<<", 2);
			advance_tokenizer(tokenizer);
		}
		add_token(tokenizer, "<", 1);
		advance_tokenizer(tokenizer);
	}
}
