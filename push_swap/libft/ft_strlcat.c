/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:26:16 by fthwala           #+#    #+#             */
/*   Updated: 2017/07/31 17:01:34 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	x;
	size_t	y;

	x = ft_strlen(dest);
	y = ft_strlen(src);
	i = 0;
	if (!(n > x))
		return (n + y);
	while (src[i] && ((x + i) < (n - 1)))
	{
		dest[x + i] = src[i];
		i++;
	}
	dest[x + i] = '\0';
	return (x + y);
}
