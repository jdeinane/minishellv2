/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:36:21 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 11:12:18 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_tokenizer	*init_tokenizer(const char *input)
{
	t_tokenizer	*tokenizer;

	tokenizer = malloc(sizeof(t_tokenizer));
	if (!tokenizer)
	{
		exit(1);
		return (NULL);
	}
	tokenizer->tokens = NULL;
	tokenizer->start = input;
	tokenizer->current_quote = 0;
	tokenizer->in_quote = false;
	tokenizer->error = false;
	tokenizer->count = 0;
	tokenizer->input = input;
	tokenizer->size = 0;
	return (tokenizer);
}
