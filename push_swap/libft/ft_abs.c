/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:56:18 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 11:55:40 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int a)
{
	return (a >= 0 ? a : -a);
}

void	ft_addnbr(int **arr, int a)
{
	int index;
	int index2;
	int *tmp;

	index = sizeof(*arr) / sizeof(*arr[0]);
	index2 = 0;
	if (!(tmp = (int*)malloc(sizeof(int ) * index)))
		return ;
	while (index2 < index)
	{
		tmp[index2] = *arr[index2];
		index2++;
	}
	index2 = 0;
	if (!(*arr = (int*)malloc(sizeof(int) * (index + 1))))
		return ;
	while (index2 < index)
	{
		*arr[index2] = tmp[index2];
		index2++;
	}
	*arr[index2] = a;
	free(tmp);
	tmp = NULL;
}
