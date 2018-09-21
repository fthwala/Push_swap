/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:12:14 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 13:42:29 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_instruction(t_instruction ret)
{
	if (ret == sa)
		ft_putendl("sa");
	else if (ret == pa)
		ft_putendl("pa");
	else if (ret == pb)
		ft_putendl("pb");
	else if (ret == ra)
		ft_putendl("ra");
	else if (ret == rra)
		ft_putendl("rra");
	else if (ret == rb)
		ft_putendl("rb");
	else if (ret == rrb)
		ft_putendl("rrb");
	else if (ret == rr)
		ft_putendl("rr");
	else
		ft_putendl("rrr");
}

static void		update_stacks(t_stack **a, t_stack **b, int items)
{
	t_instruction	ret;

	while ((ret = decision(a, b, items)) != ok)
	{
		print_instruction(ret);
		if (ret == sa)
			swap(a);
		else if (ret == pa)
			push_on(a, b);
		else if (ret == pb)
			push_on(b, a);
		else if (ret == ra)
			rotate_up(a);
		else if (ret == rra)
			rotate_dwn(a);
		else if (ret == rb)
			rotate_up(b);
		else if (ret == rrb)
			rotate_dwn(b);
		else if (ret == rr)
			rotate_up_rr(a, b);
		else
			rotate_dwn_rrr(a, b);
	}
}

int				main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				to_free;

	argv = argv + 1;
	to_free = (argc == 2 && ft_contains(argv[0], ' ') ? 1 : 0);
	argv = check_env_args(argc, argv);
	argc = (to_free ? ft_items_in_grid((void **)argv) + 1 : argc);
	check_args_err(argc, argv);
	stack_a = init_stack(argc - 1, argv);
	stack_b = NULL;
	if (to_free)
		ft_destroy_2d((void **)argv);
	update_stacks(&stack_a, &stack_b, count(&stack_a));
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	return (0);
}
