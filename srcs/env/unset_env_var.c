/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:40:37 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 13:34:06 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	unset_env_var(char **envp, const char *var_name)
{
	int (index) = get_env_var_index(envp, var_name);
	int (i) = index;
	if (index == -1)
		return (1);
	free(envp[index]);
	while (envp[i])
	{
		envp[i] = envp[i + 1];
		i++;
	}
	return (0);
}
