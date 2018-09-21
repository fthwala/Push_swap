/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:10:27 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 15:27:59 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				pos_2b(t_stack **b, int num, int index)
{
	int i;

	i = 0;
	if (count(b) == 1 || count(b) == 0)
		return (index);
	else if (rsorted(b) && (num > top(b) || num < bottom(b)))
	{
		while (i++ < index)
			rotate_dwn(b);
		return (index);
	}
	else if (bottom(b) > num && num > top(b))
	{
		while (i++ < index)
			rotate_dwn(b);
		return (index);
	}
	else
	{
		rotate_up(b);
		return (pos_2b(b, num, index + 1));
	}
}

t_instruction	sort3(t_stack **a)
{
	if (is_sorted(a))
		return (ok);
	else if (rsorted(a) || top(a) == max(a))
		return (ra);
	else if (sec(a) == min(a))
		return (sa);
	else
		return (rra);
}

t_instruction	sort10(t_stack **a, t_stack **b)
{
	int				items;

	items = count(a);
	if (is_sorted(a) && *b == NULL)
		return (ok);
	if (*b && is_sorted(a) && rsorted(b))
		return (pa);
	if (items == 3)
	{
		if (sort3(a) == ok)
			return (pa);
		else
			return (sort3(a));
	}
	if (top(a) == min(a))
		return (pb);
	else
		return (num_pos(a, min(a)) <= items / 2 ? ra : rra);
}

t_instruction	sort(int push2b, t_stack **a, t_stack **b)
{
	int items;

	items = count(a);
	if (direction(push2b, a, b) > 0)
		return (rr);
	else if (direction(push2b, a, b) < 0)
		return (rrr);
	else
	{
		if (push2b == top(a))
		{
			if (pos_2b(b, push2b, 0) == 0)
				return (pb);
			else
				return (pos_2b(b, push2b, 0) <= count(b) / 2 ? rb : rrb);
		}
		else
			return (num_pos(a, push2b) <= items / 2 ? ra : rra);
	}
}

t_instruction	decision(t_stack **a, t_stack **b, int items)
{
	int		push2b;

	if (items == 2)
		return (is_sorted(a) ? ok : sa);
	else if (items == 3)
		return (sort3(a));
	else if (items <= 10)
		return (sort10(a, b));
	else
	{
		if (is_sorted(a) && *b == NULL)
			return (ok);
		else if (*b && is_sorted(a) && rsorted(b) && (!*a || top(a) > top(b)))
			return (pa);
		else if (*b && is_sorted(a) && !rsorted(b) && (!*a || top(a) > max(b)))
			return (num_pos(b, min(b)) < count(b) / 2 ? rb : rrb);
		else
		{
			push2b = get_to_be_pushed(a, b);
			return (sort(push2b, a, b));
		}
	}
}
