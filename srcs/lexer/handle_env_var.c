/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:03:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 11:14:41 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool validenvchar(char c)
{
    return (isalnum(c) || c == '_');
}

static char	*extract_env_var_name(const char *input, int len)
{
	char	*name;

	name = malloc(len + 1);
	if (!name)
		return (NULL);
	ft_strncpy(name, input, len);
	name[len] = '\0';
	return (name);
}

void	handle_env_variables(t_tokenizer *tokenizer)
{
	int (start_index) = tokenizer->start - tokenizer->input + 1;
	int (len) = 0;
	char (*env_var_name);
	char (*env_var_value);
	advance_tokenizer(tokenizer);
	while (more_tokens_available(tokenizer) && validenvchar(current_char(tokenizer)))
	{
		advance_tokenizer(tokenizer);
		len++;
	}
	env_var_name = extract_env_var_name(tokenizer->input + start_index, len);
	env_var_value = getenv(env_var_name);
	if (env_var_value)
		add_token(tokenizer, env_var_value, ft_strlen(env_var_value));
	else
		add_token(tokenizer, "", 0);
	free(env_var_name);
}
