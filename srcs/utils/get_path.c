/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:16:04 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 18:19:50 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**get_paths(char **envp)
{
	char	**paths;
	char	*path_var;
	char	*token;
	int		path_count;
	int		i;
	int		j;

	i = 0;
	path_var = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_var = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (path_var == NULL)
		return (NULL);
	path_count = 1;
	while (path_var[i] != '\0')
	{
		if (path_var[i] == ':')
			path_count++;
		i++;
	}
	paths = malloc((path_count + 1) * sizeof(char *));
	if (paths == NULL)
		return (NULL);
	j = 0;
	token = ft_strtok(path_var, ":");
	while (token != NULL)
	{
		paths[j++] = ft_strdup(token);
		token = ft_strtok(NULL, ":");
	}
	paths[j] = NULL;
	return (paths);
}
