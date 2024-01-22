/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:07:50 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/22 16:10:24 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_exit(char **av, int last_exit_status)
{
	long	status;

	if (av[1] == NULL)
		exit(last_exit_status);
	if (!is_numeric(av[1]))
	{
		write(STDERR_FILENO, "exit: numeric argument required\n", 32);
		exit(255);
	}
	status = ft_strtol(av[1], NULL, 10);
	if (status < 0 || status > 255)
		status = (unsigned char) status;
	exit((int)status);
}
