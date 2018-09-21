/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:09:57 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 11:54:33 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			end;
	size_t			len;
	char			*str;
	char			*s1;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	start = 0;
	len = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] == ' ' || s1[start] == '\n' || s1[start] == '\t')
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (s1[end] == ' ' || s1[end] == '\n' || s1[end] == '\t')
		end--;
	len = end - start;
	str = ft_strsub(s1, start, len + 1);
	return (str);
}

char	*ft_strcuthead(char **s, int c)
{
	char *temp;

	if (!*s)
		return (NULL);
	if (!(temp = ft_strsub(*s, c, ft_strlen(*s) - c)))
		return (NULL);
	if (*s)
		free(*s);
	if (!(*s = (char*)malloc(ft_strlen(temp) + 1)))
		return (NULL);
	ft_bzero((void*)(*s), ft_strlen(temp) + 1);
	ft_strcpy(*s, temp);
	free(temp);
	temp = NULL;
	return (*s);
}
