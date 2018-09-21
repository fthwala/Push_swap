/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:25:09 by fthwala           #+#    #+#             */
/*   Updated: 2017/08/18 14:57:59 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *heystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*need;
	char	*hey;

	i = 0;
	j = 0;
	hey = (char *)heystack;
	need = (char *)needle;
	j = ft_strlen(need);
	if (need[0] == '\0' && hey[0] == '\0')
		return (hey);
	while (hey[i])
	{
		if (need[0] == '\0')
			return (&hey[i]);
		if (hey[i] == need[0])
			if (ft_strncmp(&hey[i], need, j) == 0)
				return (&hey[i]);
		i++;
	}
	return (NULL);
}
