/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:48:57 by fthwala           #+#    #+#             */
/*   Updated: 2017/08/18 12:41:56 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;
	size_t			i;

	ndst = (unsigned char*)dest;
	nsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		if (nsrc[i] == (unsigned char)c)
			return (&ndst[i + 1]);
		i++;
	}
	return (NULL);
}
