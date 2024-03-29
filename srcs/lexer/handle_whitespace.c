/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_whitespace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:53:16 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/25 15:43:39 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_whitespace(t_tokenizer *tokenizer)
{
	while (is_space(current_char(tokenizer)
			&& more_tokens_available(tokenizer)))
		advance_tokenizer(tokenizer);
}
