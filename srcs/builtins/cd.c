/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:39:13 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 18:47:51 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_cd(char **av, char **envp)
{
	char	*old_path;
	char	*new_path;
	char	*current_path;

	old_path = getcwd(NULL, 0);
	if (av[1] == NULL || ft_strcmp(av[1], "~") == 0)
		new_path = get_env_var(*envp, "HOME");
	else if (ft_strcmp(av[1], "-") == 0)
	{
		if (new_path == NULL)
		{
			free(old_path);
			write(STDERR, "minishell: cd: OLDPWD not set\n", 30);
			return (1);
		}
	}
	else
		new_path = av[1];
	if (chdir(new_path) != 0)
	{
		perror("cd");
		free(old_path);
		return (1);
	}
	set_env_var(envp, "OLDPWD", old_path);
	free(old_path);
	current_path = getcwd(NULL, 0);
	set_env_var(envp, "PWD", current_path);
	free(current_path);
	return (0);
}
