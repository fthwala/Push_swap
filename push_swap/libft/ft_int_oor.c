/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_oor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:32:13 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 12:25:27 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_out_of_int_range(const char *str)
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
	if ((num < 0 && !ft_strchr(str, '-')) || (num > 0 && ft_strchr(str, '-')))
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
