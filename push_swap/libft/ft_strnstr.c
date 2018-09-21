/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 11:05:25 by fthwala           #+#    #+#             */
/*   Updated: 2017/06/11 17:08:29 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (big[i] != '\0')
	{
		j = i;
		k = 0;
		if (little[k] == '\0')
			return ((char*)&big[i]);
		while (big[j] && little[k] && big[j] == little[k] && j < len)
		{
			j++;
			k++;
			if (little[k] == '\0')
				return ((char*)&big[i]);
		}
		i++;
	}
	return (NULL);
}
