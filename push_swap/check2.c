/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 01:20:34 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 12:41:31 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count(t_stack **stack)
{
	int		items;
	t_stack *hold;

	items = 0;
	if (!*stack)
		return (items);
	else
	{
		hold = *stack;
		while (hold)
		{
			items++;
			hold = hold->next;
		}
		return (items);
	}
}

int		top(t_stack **stack)
{
	return ((*stack)->num);
}

int		sec(t_stack **stack)
{
	return ((*stack)->next->num);
}

int		bottom(t_stack **stack)
{
	t_stack *hold;

	hold = *stack;
	while (hold)
	{
		if (hold->next == NULL)
			break ;
		hold = hold->next;
	}
	return (hold->num);
}

int		num_pos(t_stack **stack, int num)
{
	int		index;
	t_stack *hold;

	hold = *stack;
	index = 0;
	while (hold)
	{
		if (hold->num == num)
			break ;
		hold = hold->next;
		index++;
	}
	return (index);
}
