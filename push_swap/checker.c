/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:06:57 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 15:14:55 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		update_stacks(t_stack **a, t_stack **b, char *line)
{
	if (ft_strequ(line, "sa"))
		swap(a);
	else if (ft_strequ(line, "sb"))
		swap(b);
	else if (ft_strequ(line, "ss"))
		swap_ss(a, b);
	else if (ft_strequ(line, "pa"))
		push_on(a, b);
	else if (ft_strequ(line, "pb"))
		push_on(b, a);
	else if (ft_strequ(line, "ra"))
		rotate_up(a);
	else if (ft_strequ(line, "rra"))
		rotate_dwn(a);
	else if (ft_strequ(line, "rb"))
		rotate_up(b);
	else if (ft_strequ(line, "rrb"))
		rotate_dwn(b);
	else if (ft_strequ(line, "rr"))
		rotate_up_rr(a, b);
	else if (ft_strequ(line, "rrr"))
		rotate_dwn_rrr(a, b);
}

int				main(int argc, char **argv)
{
	char	*line;
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		to_free;

	argv = argv + 1;
	to_free = (argc == 2 && ft_contains(argv[0], ' ') ? 1 : 0);
	argv = check_env_args(argc, argv);
	argc = (to_free ? ft_items_in_grid((void **)argv) + 1 : argc);
	check_args_err(argc, argv);
	line = NULL;
	stk_a = init_stack(argc - 1, argv);
	stk_b = NULL;
	while (get_next_line(0, &line) > 0 && valid_cmd(line))
		update_stacks(&stk_a, &stk_b, line);
	if (line && !valid_cmd(line))
		ft_putendl("Error");
	else
		ft_putendl(sorted(&stk_a, &stk_b) ? "OK" : "KO");
	destroy_stack(&stk_a);
	destroy_stack(&stk_b);
	free(line);
	if (to_free)
		ft_destroy_2d((void **)argv);
	return (0);
}
