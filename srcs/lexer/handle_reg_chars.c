/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_reg_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:16:04 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 11:20:58 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	is_special_char(char c)
{
	return (is_space(c) || is_quote(c) || is_operator(c) || is_env_var(c));
}

static char *extract_token(const char *input, int start, int len)
{
	char	*token;

	token = malloc(len + 1);
	if (!token)
	{
		g_status_code = 1;
		return (NULL);
	}
	ft_strncpy(token, input + start, len);
	token[len] = '\0';
	return (token);
}

void	handle_regular_chars(t_tokenizer *tokenizer)
{
	int (start_index) = tokenizer->start - tokenizer->input;
	int (len) = 0;
	char (*token);
	while (more_tokens_available(tokenizer) && !is_special_char(current_char(tokenizer)))
	{
		advance_tokenizer(tokenizer);
		len++;
	}
	if (len > 0)
	{
		token = extract_token(tokenizer->input + start_index, len);
		add_token(tokenizer, token, len);
		free(token);
	}
}
