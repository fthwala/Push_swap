/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 09:56:15 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 11:57:28 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static int	spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int	num;
	int	i;
	int	negative;

	i = spaces(str);
	num = 0;
	negative = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (negative)
		return (-num);
	else
		return (num);
}

int			ft_htoi(const char *s)
{
	unsigned long int	ret;
	int					index;

	index = 0;
	ret = 0;
	while ((int)ft_strlen(s) - (++index) >= 0)
	{
		if (s[index - 1] == 'a' || s[index - 1] == 'A')
			ret += 10 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'b' || s[index - 1] == 'B')
			ret += 11 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'c' || s[index - 1] == 'C')
			ret += 12 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'd' || s[index - 1] == 'D')
			ret += 13 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'e' || s[index - 1] == 'E')
			ret += 14 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'f' || s[index - 1] == 'F')
			ret += 15 * (pow(16, (ft_strlen(s) - index)));
		else if (ft_isdigit(s[index - 1]))
			ret += (s[index - 1] - '0') * (pow(16, (ft_strlen(s) - index)));
		else
			return (-1);
	}
	return (ret > 9223372036854775807 ? -1 : ret);
}
