/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:29:15 by fthwala           #+#    #+#             */
/*   Updated: 2017/08/18 12:48:03 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				index;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	index = 0;
	while (s[index] && d[index] && s1[index] == s2[index])
		index++;
	return (s[index] - d[index]);
}
