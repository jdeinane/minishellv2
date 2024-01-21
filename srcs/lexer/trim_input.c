/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:09:03 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 18:13:42 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*trim_input(const char *input)
{
	const char	*end;
	char		*trimmed;
	size_t		len;

	if (input == NULL)
		return (NULL);
	while (is_space((unsigned char)*input))
		input++;
	if (*input == 0)
		return (ft_strdup(""));
	end = input + ft_strlen(input) - 1;
	while (end > input && is_space((unsigned char)*end))
		end--;
	len = end - input + 1;
	trimmed = malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strncpy(trimmed, input, len);
	trimmed[len] = '\0';
	return (trimmed);
}
