/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:51:07 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 12:56:48 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rotate_up(t_stack **stack)
{
	t_stack		*temp;
	t_stack		*hold;

	hold = *stack;
	if (hold && hold->next)
	{
		*stack = (*stack)->next;
		hold->next = NULL;
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = hold;
	}
}

void			rotate_dwn(t_stack **stack)
{
	t_stack		*temp;
	t_stack		*hold;

	hold = *stack;
	if (*stack && (*stack)->next)
	{
		while (hold->next)
		{
			temp = hold;
			hold = hold->next;
		}
		temp->next = NULL;
		hold->next = *stack;
		*stack = hold;
	}
}

void			rotate_up_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_up(stack_a);
	rotate_up(stack_b);
}

void			rotate_dwn_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_dwn(stack_a);
	rotate_dwn(stack_b);
}
