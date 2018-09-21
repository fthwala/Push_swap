/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:45:35 by fthwala           #+#    #+#             */
/*   Updated: 2017/08/18 08:49:13 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*d;
	char	*s;
	int		i;

	d = (char *)s1;
	s = (char *)s2;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str == NULL)
		return (NULL);
	while (*d)
	{
		str[i++] = *d;
		d++;
	}
	while (*s)
	{
		str[i++] = *s;
		s++;
	}
	str[i] = '\0';
	return (str);
}
