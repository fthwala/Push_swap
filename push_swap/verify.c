/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 01:17:24 by fthwala           #+#    #+#             */
/*   Updated: 2017/12/04 10:47:45 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted(t_stack **stack)
{
	t_stack *hold;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	else if ((*stack)->next->next == NULL)
		return ((*stack)->num < (*stack)->next->num ? 1 : 0);
	else
	{
		hold = *stack;
		while (hold && hold->next)
		{
			if (hold->num > hold->next->num)
				return (0);
			hold = hold->next;
		}
		return (1);
	}
}

int			rsorted(t_stack **stack)
{
	t_stack *hold;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	else if ((*stack)->next->next == NULL)
		return ((*stack)->num > (*stack)->next->num ? 1 : 0);
	else
	{
		hold = *stack;
		while (hold && hold->next)
		{
			if (hold->num < hold->next->num)
				return (0);
			hold = hold->next;
		}
		return (1);
	}
}

int			sorted(t_stack **a, t_stack **b)
{
	if (is_sorted(a) && *b == NULL)
		return (1);
	return (0);
}

int			valid_args(int argc, char **argv)
{
	int		index;

	index = 0;
	if (argc == 0)
		return (0);
	while (index < argc)
	{
		if (!ft_is_number(argv[index]))
			return (0);
		if (ft_out_of_int_range((const char *)argv[index]))
			return (0);
		index++;
	}
	return (1);
}

int			valid_cmd(char *line)
{
	if (ft_strequ(line, "sa"))
		return (1);
	else if (ft_strequ(line, "sb"))
		return (1);
	else if (ft_strequ(line, "ss"))
		return (1);
	else if (ft_strequ(line, "pa"))
		return (1);
	else if (ft_strequ(line, "pb"))
		return (1);
	else if (ft_strequ(line, "ra"))
		return (1);
	else if (ft_strequ(line, "rra"))
		return (1);
	else if (ft_strequ(line, "rb"))
		return (1);
	else if (ft_strequ(line, "rrb"))
		return (1);
	else if (ft_strequ(line, "rr"))
		return (1);
	else if (ft_strequ(line, "rrr"))
		return (1);
	else
		return (0);
}
