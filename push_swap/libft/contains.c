/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:30:10 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 11:45:09 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contains(char *s, char c)
{
	int index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}

int		ft_contains_str(const char **argv, const char *str, int len)
{
	int		index;

	index = 0;
	while (index < len)
	{
		if (ft_strequ(argv[index], str))
			return (1);
		index++;
	}
	return (0);
}

int		ft_items_in_grid(void **grid)
{
	int index;

	index = 0;
	while (grid[index])
		index++;
	return (index);
}
