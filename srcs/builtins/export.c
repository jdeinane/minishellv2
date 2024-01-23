/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:24:33 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 19:01:47 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	export(char **av, char **envp)
{
	int		i;
	char	*name;
	char	*value;
	char	*error_msg;

	i = 0;
	if (av[1] == NULL)
	{
		while (envp[i] != NULL)
		{
			write(STDOUT, "declare -x ", 11);
			write(STDOUT, envp[i], ft_strlen(envp[i]));
			write(STDOUT, "\n", 1);
			i++;
		}
		return (0);
	}
	i = 1;
	while (av[i] != NULL)
	{
		name = ft_strtok(av[i], "=");
		value = ft_strtok(NULL, "");
		if (name != NULL && value != NULL)
		{
			if (set_env_var(envp, name, value))
			{
				error_msg = "export: Error setting variable\n";
				write(STDERR, error_msg, ft_strlen(error_msg));
				return (1);
			}
		}
		else
		{
			error_msg = "export: not a valid identifier\n";
			write(STDERR, error_msg, ft_strlen(error_msg));
			return (1);
		}
		i++;
	}
	return (0);
}
