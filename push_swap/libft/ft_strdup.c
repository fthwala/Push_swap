/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:28:57 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/05 01:42:55 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	index;

	index = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	if (src == NULL)
		return (NULL);
	while (index <= (ft_strlen(src)))
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
