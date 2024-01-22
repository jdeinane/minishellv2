/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:50:55 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 19:17:19 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	set_env_var(char **envp, const char *name, const char *value)
{
	int		index;
	int		i;
	size_t	name_len;
	size_t	value_len;
	size_t	env_size;
	char	**new_env;
	char	*new_var;

	index = get_env_var_index(*envp, name);
	name_len = ft_strlen(name);
	i = 0;
	value_len = 0;
	if (value != NULL)
		value_len = ft_strlen(value);
	new_var = malloc(name_len + value_len + 2);
	if (new_var == NULL)
		return (-1);
	ft_strcpy(new_var, name);
	new_var[name_len] = '=';
	if (value != NULL)
		ft_strcpy(new_var + name_len + 1, value);
	else
		new_var[name_len + 1] = '\0';
	if (index != -1)
	{
		free(envp[index]);
		envp[index] = new_var;
	}
	else
	{
		env_size = env_var_count(envp);
		new_env = malloc(sizeof(char *) * (env_size + 2));
		if (new_env == NULL)
		{
			free(new_var);
			return (-1);
		}
		while (i < env_size)
		{
			new_env[i] = envp[i];
			i++;
		}
		new_env[env_size] = new_var;
		new_env[env_size + 1] = NULL;
		free(envp);
		envp = new_env;
	}
	return (0);
}
