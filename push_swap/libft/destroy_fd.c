/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:52:10 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 12:24:03 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		destroy_1(t_fd **list)
{
	t_fd	*hold;

	if (*list)
	{
		hold = (*list)->next;
		if ((*list)->store)
		{
			free((*list)->store);
			(*list)->store = NULL;
		}
		free(*list);
		*list = NULL;
		*list = hold;
	}
}

void			destroy_fd(const int fd, t_fd **list)
{
	t_fd	*hold1;
	t_fd	*hold2;

	if (*list)
	{
		if ((*list)->fd == fd)
			destroy_1(list);
		else
		{
			hold1 = *list;
			hold2 = *list;
			while (*list)
			{
				if ((*list)->fd == fd)
				{
					destroy_1(list);
					hold2->next = *list;
					break ;
				}
				hold2 = *list;
				*list = (*list)->next;
			}
			*list = hold1;
		}
	}
}

void			**ft_destroy_2d(void **grid)
{
	int index;

	if (grid)
	{
		index = 0;
		while (grid[index])
		{
			ft_memdel(&grid[index]);
			index++;
		}
		free(grid);
		grid = NULL;
	}
	return (NULL);
}
