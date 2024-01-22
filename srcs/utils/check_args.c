/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:16:45 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/13 18:20:08 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	check_args(int ac, char **av)
{
	if (ac != 1)
	{
		printf("Usage: %s\n", av[0]);
		return (false);
	}
	return (true);
}
