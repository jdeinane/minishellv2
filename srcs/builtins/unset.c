/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:37:25 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 13:27:51 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_unset(char **av, char **envp)
{
	int		i;
	char	*error_msg;

	i = 1;
	while (av[i] != NULL)
	{
		if (unset_env_var(envp, av[i]) != 0)
		{
			error_msg = "unset: failed to unset variable\n";
			write(STDERR, error_msg, ft_strlen(error_msg));
			return (1);
		}
	}
	return (0);
}
