/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:28:38 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 16:31:01 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	minishell(int ac, char **av, char **envp)
{
	t_data		*data;
	char		*prompt;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_minishell(NULL, EXIT_FAILURE);
	prompt = get_prompt();
	if (!check_args(ac, av) || !init_data(data, envp))
	{
		free_ptr(prompt);
		exit_minishell(NULL, EXIT_FAILURE);
	}
	while (true)
	{
		signals_wait_cmd();
		data->user_input = readline(prompt);
		signals_run_cmd();
		free_ptr(prompt);
		if (input_handler(data))
			g_status_code = execute(data);
		prompt = get_prompt();
		if (!prompt)
			exit_minishell(data, EXIT_FAILURE);
	}
}
