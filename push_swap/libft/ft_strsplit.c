/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 14:37:40 by fthwala           #+#    #+#             */
/*   Updated: 2017/08/21 09:43:54 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s, char c)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s)
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	ft_wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;
	int		now;

	if (!s)
		return (NULL);
	i = 0;
	now = ft_count((char*)s, c);
	if ((str = (char **)malloc(sizeof(char *) * (now + 1))))
	{
		while (now--)
		{
			while (*s == c && *s)
				s++;
			str[i++] = ft_strsub(s, 0, ft_wordlen(s, c));
			if (!str)
				return (NULL);
			s = s + ft_wordlen(s, c);
		}
		str[i] = NULL;
	}
	return (str);
}
