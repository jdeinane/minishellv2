/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:24:33 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 19:36:17 by jubaldo          ###   ########.fr       */
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
		return (display_all_env_vars(envp));
	i = 1;
	while (av[i] != NULL)
	{
		if (!is_valid_env_var_name(av[i]))
		{
			error_msg = "export: not a valid identifier\n";
			write(STDERR, error_msg, ft_strlen(error_msg));
			return (1);
		}
		name = ft_strtok(av[i], "=");
		value = ft_strtok(NULL, "=");
		if (name == NULL || value == NULL)
		{
			error_msg = "export: memory allocation error\n";
			write(STDERR, error_msg, ft_strlen(error_msg));
			return (1);
		}
		if (set_env_var(envp, name, value))
		{
			error_msg = "export: Error setting variable\n";
			write(STDERR, error_msg, ft_strlen(error_msg));
			return (1);
		}
		i++;
	}
	return (0);
}

static bool	is_valid_env_var_name(const char *str)
{
	if (!str || !(*str == '_' || ft_isalpha(*str)))
		return (false);
	str++;
	while (*str)
	{
		if (!(*str == '_' || ft_isalnum(*str)))
			return (false);
		str++;
	}
	return (true);
}

static int	display_all_env_vars(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (1);
	while (envp[i] != NULL)
	{
		write(STDOUT, "declare -x ", 11);
		write(STDOUT, envp[i], ft_strlen(envp[i]));
		write(STDOUT, "\n", 1);
	}
	return (0);
}
