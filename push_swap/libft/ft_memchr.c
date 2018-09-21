/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:12:18 by fthwala           #+#    #+#             */
/*   Updated: 2017/06/11 16:18:11 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*nc;

	nc = (unsigned char *)str;
	while (n > 0)
	{
		if (*nc == (unsigned char)c)
			return (nc);
		else
			nc++;
		n--;
	}
	return (0);
}
