/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:44:16 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 12:43:03 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_number(char *s)
{
	int index;

	index = 0;
	if ((s[index] == '+' || s[index] == '-') && s[index + 1])
		index++;
	while (s[index])
	{
		if (!ft_isdigit(s[index]))
			return (0);
		index++;
	}
	return (1);
}

int		checker(long int num, char *str)
{
	if ((num < 0 && !ft_strchr((char *)str, '-')) ||
			(num > 0 && ft_strchr((char *)str, '-')))
		return (1);
	return (0);
}

int		ft_out_of_int_range(const char *str)
{
	int			index;
	int			len;
	long int	num;
	long int	div;

	div = 1;
	len = ft_strlen(str);
	num = ft_atoi(str);
	index = (str[0] == '-' || str[0] == '+' ? 1 : 0);
	while (str[index] == '0')
		index++;
	if (checker(num, (char *)str) == 1)
		return (1);
	num = (num < 0 ? num * -1 : num);
	while (div <= num)
		div *= 10;
	div /= 10;
	while (str[index] && div != 0)
	{
		if (str[index++] != (num / div) + '0')
			return (1);
		num %= div;
		div /= 10;
	}
	return (index == len || (div == 0 && index < len) ? 0 : 1);
}
