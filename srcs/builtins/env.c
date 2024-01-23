/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:01:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 18:49:21 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		write(STDOUT, envp[i], ft_strlen(envp[i]));
		write(STDOUT, "\n", 1);
		i++;
	}
	return (0);
}
