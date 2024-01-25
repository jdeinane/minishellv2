/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:26:52 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 14:38:53 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_env_var_index(char **envp, const char *var_name)
{
	int (i) = 0;
	int (len) = ft_strlen(var_name);
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
	int		i;
	char	*tmp;
	char	*result;

	i = 0;
	tmp = ft_strjoin(var_name, "=");
	if (!tmp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(tmp, envp[i], ft_strlen(tmp)) == 0)
		{
			free_ptr(tmp);
			result = ft_strchr(envp[i], '=') + 1;
			return (result);
		}
		i++;
	}
	free_ptr(tmp);
	return (NULL);
}

char	*get_env_var(char **envp, char *var_name)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(var_name);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var_name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}
