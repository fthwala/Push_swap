/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:24:31 by fthwala           #+#    #+#             */
/*   Updated: 2017/06/11 16:08:35 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	s;
	int				index;

	s = c;
	index = ft_strlen(str);
	while (index >= 0)
	{
		if (str[index] == s)
			return ((char *)str + index);
		index--;
	}
	return (NULL);
}
