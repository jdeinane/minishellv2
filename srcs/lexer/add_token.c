/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:56:36 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 13:55:45 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_token(t_tokenizer *tokenizer, const char *start, int len)
{
	char (*token) = malloc(len + 1);
	int (i) = 0;
	int (new_size) = tokenizer->count + 1;
	char (**new_tokens);
	if (!token)
	{
		tokenizer->error = true;
		return ;
	}
	ft_strncpy(token, start, len);
	token[len] = '\0';
	new_tokens = malloc(sizeof(char *) * new_size);
	if (!new_tokens)
	{
		free(token);
		tokenizer->error = true;
		return ;
	}
	while (i < tokenizer->count)
	{
		new_tokens[i] = tokenizer->tokens[i];
		i++;
	}
	new_tokens[tokenizer->count] = token;
	free(tokenizer->tokens);
	tokenizer->tokens = new_tokens;
	tokenizer->count++;
}
