/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:51:32 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/18 18:15:00 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_stack **stack, t_stack *item)
{
	if (item)
	{
		item->next = *stack;
		*stack = item;
	}
}

t_stack		*pop(t_stack **stack)
{
	t_stack		*ret;

	ret = NULL;
	if (!*stack)
		return (ret);
	else
	{
		ret = *stack;
		*stack = (*stack)->next;
		ret->next = NULL;
		return (ret);
	}
}

void		push_on(t_stack **dest, t_stack **src)
{
	push(dest, pop(src));
}
