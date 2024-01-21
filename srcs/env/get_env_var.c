/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:26:52 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 18:50:15 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_env_var_index(char **envp, char *var_name)
{
	int	i;
	int	len;

	len = ft_strlen(var_name);
	i = 0;
	if (envp == NULL || var_name == NULL)
		return (-1);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var_name, len) == 0 && envp[i][len] == '=')
			return (i);
	}
	return (-1);
}

char	*get_env_var_value(char **envp, char *var_name)
{
	int		index;
	char	*value_start;

	index = get_env_var_index(envp, var_name);
	if (envp == NULL || var_name == NULL)
		return (NULL);
	if (index == -1)
		return (NULL);
	value_start = ft_strchr(envp[index], '=');
	if (value_start != NULL && *(++value_start) != '\0')
		return (ft_strdup(value_start));
	return (NULL);
}

char	*get_env_var(char **envp, char *var_name)
{
	size_t	len;

	len = ft_strlen(var_name);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var_name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}
