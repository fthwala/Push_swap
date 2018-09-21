/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:51:07 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 12:57:09 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_stack **stack)
{
	int		temp_num;

	temp_num = 0;
	if (*stack && (*stack)->next)
	{
		temp_num = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = temp_num;
	}
}

void		swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
