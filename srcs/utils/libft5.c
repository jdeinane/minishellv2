/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:49:19 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/23 15:58:43 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (i);
}

static int	parse_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	get_base(const char *str, int *index, int base)
{
	if (base == 0)
	{
		if (str[*index] == '0')
		{
			(*index)++;
			if (str[*index] == 'x' || str[*index] == 'X')
			{
				base = 16;
				(*index)++;
			}
			else
				base = 8;
		}
		else
			base = 10;
	}
	return (base);
}

static int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (10 + c - 'a');
	if (c >= 'A' && c <= 'Z')
		return (10 + c - 'A');
	return (0);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	int (i) = skip_whitespace(str);
	int (sign) = parse_sign(str, &i);
	int (digit);
	long (result) = 0;
	base = get_base(str, &i, base);
	while (ft_isalnum(str[i]))
	{
		digit = char_to_digit(str[i]);
		if (result > (LONG_MAX - digit) / base)
		{
			if (sign == 1)
				result = LONG_MAX;
			else
				result = LONG_MIN;
			break ;
		}
		result = result * base + digit;
		i++;
	}
	if (endptr != NULL)
		*endptr = (char *)(str + i);
	return (result * sign);
}

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char*)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
