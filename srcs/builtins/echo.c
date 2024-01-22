/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:09:59 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/22 15:16:03 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_echo(char **av)
{
	bool (newline) = true;
	int (i) = 1;
	if (av[1] != NULL && ft_strcmp(av[1], "-n") == 0)
	{
		newline = false;
		i = 2;
	}
	while (av[i] != NULL)
	{
		write(STDOUT, av[i], ft_strlen(av[i]));
		if (av[i + 1] != NULL)
			write(STDOUT, " ", 1);
		i++;
	}
	if (newline)
		write(STDOUT, "\n", 1);
	return (0);
}
