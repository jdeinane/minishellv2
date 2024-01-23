/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_trucnuche.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:36:43 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 23:29:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (c);
	return (0);
}

bool	is_digit2(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c < '0' + base);
	else
	{
		if ((c >= '0' && c <= '9')
			|| (c >= 'a' && c < 'a' + base - 10)
			|| (c >= 'A' && c < 'A' + base - 10))
			return (true);
		else
			return (false);
	}
}

bool	is_numeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_command(char **tokens, int token_index)
{
	if (token_index == 0)
		return (true);
	if (tokens[token_index - 1] && ft_strcmp(tokens[token_index - 1], "|") == 0)
		return (true);
	return (false);
}

bool	is_argument(char **tokens, int token_index, t_commands *cmds)
{
	if (token_index == 0)
		return (false);
	if (is_command(tokens, token_index - 1) || is_operator(tokens[token_index - 1]))
		return (false);
	if (is_redirection(tokens[token_index]))
		return (false);
	return (true);
}

bool	is_redirection(char *token)
{
	if (ft_strcmp(token, ">") == 0 || ft_strcmp(token, ">>") == 0 ||
		ft_strcmp(token, "<") == 0 || ft_strmp(token, "<<") == 0)
		return (true);
	return (false);
}