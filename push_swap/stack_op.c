/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 01:06:15 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 12:18:22 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			in_stack_already(t_stack **a, int num)
{
	t_stack *hold;

	if (!*a)
		return (0);
	hold = *a;
	while (hold)
	{
		if (hold->num == num)
			return (1);
		hold = hold->next;
	}
	return (0);
}

t_stack		*create_stack(int num)
{
	t_stack		*ret;

	if (!(ret = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	ret->num = num;
	ret->next = NULL;
	return (ret);
}

void		destroy_stack(t_stack **stack)
{
	t_stack	*hold;

	while (*stack)
	{
		hold = *stack;
		*stack = (*stack)->next;
		free(hold);
		hold = NULL;
	}
}

t_stack		*init_stack(int argc, char **argv)
{
	int		index;
	t_stack *stack;

	index = argc - 1;
	stack = create_stack(ft_atoi(argv[index--]));
	while (index >= 0)
	{
		if (in_stack_already(&stack, ft_atoi(argv[index])))
		{
			destroy_stack(&stack);
			ft_putendl("Error");
			exit(1);
		}
		push(&stack, create_stack(ft_atoi(argv[index])));
		index--;
	}
	return (stack);
}
