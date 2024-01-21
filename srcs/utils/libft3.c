/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:44:09 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/21 18:33:40 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write (fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	write (fd, "\n", 1);
}

static size_t	is_safe(size_t nmemb, size_t size)
{
	size_t	size_max;

	size_max = LONG_MAX;
	if (!nmemb || !size)
		return (0);
	if (nmemb > size_max / size || size > size_max / nmemb)
		return (LONG_MAX);
	return (nmemb * size);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;

	str = malloc(is_safe(nmemb, size));
	if (!str)
		return (0);
	ft_memset(str, 0, is_safe(nmemb, size));
	return (str);
}
