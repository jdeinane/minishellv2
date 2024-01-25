/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:17:45 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 16:18:13 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_tokenizer(t_tokenizer *tokenizer)
{
	int	i;

	i = 0;
	if (tokenizer)
	{
		if (tokenizer->tokens)
		{
			while (i < tokenizer->count)
				free(tokenizer->tokens[i++]);
			free(tokenizer->tokens);
		}
		free(tokenizer);
	}
}
