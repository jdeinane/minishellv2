/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parsed_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:12:07 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 16:19:44 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**get_parsed_cmds_from_tokens(t_tokenizer *tokenizer)
{
	char	**parsed_cmds;
	int		i;
	int		j;

	i = 0;
	parsed_cmds = malloc(sizeof(char *) * (tokenizer->count + 1));
	if (!parsed_cmds)
	{
		g_status_code = 1;
		return (NULL);
	}
	while (i < tokenizer->count)
	{
		parsed_cmds[i] = ft_strdup(tokenizer->tokens[i]);
		if (!parsed_cmds[i])
		{
			j = 0;
			while (j < i)
				free(parsed_cmds[j++]);
			free(parsed_cmds);
			g_status_code = 1;
			return (NULL);
		}
		i++;
	}
	parsed_cmds[tokenizer->count] = NULL;
	return (parsed_cmds);
}

void	free_parsed_cmds(char **parsed_cmds)
{
	int	i;

	i = 0;
	if (parsed_cmds)
	{
		while (parsed_cmds[i] != NULL)
			free(parsed_cmds[i++]);
		free(parsed_cmds);
	}
}
