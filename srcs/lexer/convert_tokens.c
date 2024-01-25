/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:29:12 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 15:43:04 by jubaldo          ###   ########.fr       */
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
		if (!is_space(*start))
		{
			num_tokens++;
			while (!is_space(*start) && *start != '\0')
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

bool	convert_tokens_to_cmds(t_commands *cmds, char **parsed_cmds)
{
	int (i) = 0;
	int (j) = 0;
	cmds->cmds = malloc(sizeof(char *) * (cmds->num_cmds + 1));
	if (!cmds->cmds)
	{
		g_status_code = 1;
		return (false);
	}
	while (parsed_cmds[i] != NULL)
	{
		cmds->cmds[i] = ft_strdup(parsed_cmds[i]);
		if (!cmds->cmds[i])
		{
			while (j < i)
			{
				free(cmds->cmds[j]);
				j++;
			}
			free(cmds->cmds);
			g_status_code = 1;
			return (false);
		}
		i++;
	}
	cmds->cmds[cmds->num_cmds] = NULL;
	return (true);
}
