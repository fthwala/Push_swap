/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 01:19:51 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 14:05:21 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			min(t_stack **stack)
{
	int		mini;
	t_stack	*hold;

	hold = *stack;
	mini = hold->num;
	hold = hold->next;
	while (hold)
	{
		if (hold->num < mini)
			mini = hold->num;
		hold = hold->next;
	}
	return (mini);
}

int			max(t_stack **stack)
{
	int		maxi;
	t_stack	*hold;

	hold = *stack;
	maxi = hold->num;
	hold = hold->next;
	while (hold)
	{
		if (hold->num > maxi)
			maxi = hold->num;
		hold = hold->next;
	}
	return (maxi);
}

int			get_min_moves(int num, t_stack **a, t_stack **b)
{
	int up;
	int dn;
	int middle1;
	int middle2;

	up = MAX(num_pos(a, num), pos_2b(b, num, 0));
	dn = MAX(count(a) - num_pos(a, num) + 1, count(b) - pos_2b(b, num, 0) + 1);
	middle1 = num_pos(a, num) + count(b) - pos_2b(b, num, 0) + 1;
	middle2 = count(a) - num_pos(a, num) + 1 + pos_2b(b, num, 0);
	if (up < dn && up < MIN(middle1, middle2))
		return (up);
	else if (dn < up && dn < MIN(middle1, middle2))
		return (dn);
	else
		return (MIN(middle1, middle2));
}

int			direction(int num, t_stack **a, t_stack **b)
{
	int up;
	int dn;
	int middle1;
	int middle2;

	up = MAX(num_pos(a, num), pos_2b(b, num, 0));
	dn = MAX(count(a) - num_pos(a, num) + 1, count(b) - pos_2b(b, num, 0) + 1);
	middle1 = num_pos(a, num) + count(b) - pos_2b(b, num, 0) + 1;
	middle2 = count(a) - num_pos(a, num) + 1 + pos_2b(b, num, 0);
	if (num_pos(a, num) == 0 || pos_2b(b, num, 0) == 0)
		return (0);
	else if (up < dn && up < MIN(middle1, middle2))
		return (1);
	else if (dn < up && dn < MIN(middle1, middle2))
		return (-1);
	else
		return (0);
}

int			get_to_be_pushed(t_stack **a, t_stack **b)
{
	int		moves;
	int		ret;
	t_stack	*hold;

	if (*b == NULL)
		ret = top(a);
	else
	{
		moves = get_min_moves(top(a), a, b);
		ret = top(a);
		if ((hold = (*a)->next))
		{
			while (hold)
			{
				if (get_min_moves(top(&hold), a, b) < moves)
				{
					moves = get_min_moves(top(&hold), a, b);
					ret = top(&hold);
				}
				hold = hold->next;
			}
		}
	}
	return (ret);
}
