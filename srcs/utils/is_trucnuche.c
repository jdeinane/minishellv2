/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_trucnuche.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:36:43 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/22 18:12:06 by jubaldo          ###   ########.fr       */
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
