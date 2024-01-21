/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:34:06 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 17:50:32 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	env_size(char **envp)
{
	int		size;

	size = 0;
	while (envp[size] != NULL)
		size++;
	return (size);
}

static char	*copy_env_var(char *env_var)
{
	return (ft_strdup(env_var));
}

char	**copy_env(char **envp)
{
	int		i;
	int		j;
	int		size;
	char	**env_copy;

	size = env_size(envp);
	env_copy = malloc((size + 1) * sizeof(char *));
	if (!env_copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		env_copy[i] = copy_env_var(envp[i]);
		if (!env_copy[i])
		{
			j = 0;
			while (j < i)
				free(env_copy[j++]);
			free(env_copy);
			return (NULL);
		}
		i++;
	}
	env_copy[size] = NULL;
	return (env_copy);
}
