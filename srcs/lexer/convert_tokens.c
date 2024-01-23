/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:29:12 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 11:23:46 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_tokens(const t_tokenizer *tokenizer)
{
	int		num_tokens;
	char	*start;

	start = tokenizer->start;
	num_tokens = 0;
	while (*start != '\0')
	{
		if (!is_whitespace(*start))
		{
			num_tokens++;
			while (!is_whitespace(*start) && *start != '\0')
				start++;
		}
		else
			start++;
	}
	return (num_tokens);
}

char	*get_token(const t_tokenizer *tokenizer, int index)
{
	if (index >= 0 && index < tokenizer->count)
		return (tokenizer->tokens[index]);
	return (NULL);
}

char	**convert_tokens_to_cmds(t_tokenizer *tokenizer)
{
	int (i) = 0;
	int (j) = 0;
	int	(num_tokens) = count_tokens(tokenizer);
	char (**cmds) = malloc(sizeof(char *) * (num_tokens + 1));
	if (!cmds)
	{
		g_status_code = 1;
		return (NULL);
	}
	while (i < num_tokens)
	{
		cmds[i] = ft_strdup(get_token(tokenizer, i));
		if (!cmds[i])
		{
			while (j < i)
			{
				free(cmds[j]);
				j++;
			}
			free(cmds);
			g_status_code = 1;
			return (NULL);
		}
		i++;
	}
	cmds[num_tokens] = NULL;
	return (cmds);
}
