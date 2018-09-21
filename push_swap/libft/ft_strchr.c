/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:02:51 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 11:53:12 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	u_c;
	char			*s_hold;

	s_hold = (char*)s;
	u_c = c;
	while (*s_hold)
	{
		if (*s_hold == u_c)
			return (s_hold);
		if (*++s_hold == u_c && u_c == '\0')
			return (s_hold);
	}
	return (NULL);
}
