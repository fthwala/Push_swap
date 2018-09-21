/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:24:51 by fthwala           #+#    #+#             */
/*   Updated: 2017/06/11 16:16:31 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		index;
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	index = 0;
	while (n > 0)
	{
		d[index] = s[index];
		index++;
		n--;
	}
	return (dest);
}
