/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:49:52 by fthwala           #+#    #+#             */
/*   Updated: 2017/08/18 12:27:19 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char	const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = NULL;
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
