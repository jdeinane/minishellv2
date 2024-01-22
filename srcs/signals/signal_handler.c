/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:37:32 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/11 14:28:09 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	new_line(int sig)
{
	g_status_code = 128 + sig;
	rl_on_new_line();
	ft_putchar('\n');
}

static void	reset_prompt(int sig)
{
	g_status_code = 128 + sig;
	ft_putchar('\n');
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	signals_wait_cmd(void)
{
	signal(SIGINT, reset_prompt);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_run_cmd(void)
{
	signal(SIGINT, new_line);
	signal(SIGQUIT, new_line);
}
