/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:51:04 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 12:29:46 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# define MIN(x, y) (x > y ? y : x)
# define MAX(x, y) (x > y ? x : y)

typedef struct	s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

typedef enum	e_instruction
{
	ok,
	sa,
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb,
	rr,
	rrr
}				t_instruction;

int				sorted(t_stack **a, t_stack **b);
int				valid_args(int argc, char **argv);
int				valid_cmd(char *line);
int				is_sorted(t_stack **a);
int				rsorted(t_stack **a);
t_stack			*create_stack(int num);
t_stack			*init_stack(int argc, char **argv);
void			destroy_stack(t_stack **stack);
void			push(t_stack **stack, t_stack *item);
t_stack			*pop(t_stack **stack);
void			swap(t_stack **stack);
void			swap_ss(t_stack **stack_a, t_stack **stack_b);
void			push_on(t_stack **dest, t_stack **src);
void			rotate_up(t_stack **stack);
void			rotate_up_rr(t_stack **stack_a, t_stack **stack_b);
void			rotate_dwn(t_stack **stack);
void			rotate_dwn_rrr(t_stack **stack_a, t_stack **stack_b);
t_instruction	decision(t_stack **a, t_stack **b, int items);
int				count(t_stack **stack);
int				top(t_stack **stack);
int				sec(t_stack **stack);
int				bottom(t_stack **stack);
int				num_pos(t_stack **stack, int num);
int				min(t_stack **stack);
int				max(t_stack **stack);
int				get_min_moves(int num, t_stack **a, t_stack **b);
int				direction(int num, t_stack **a, t_stack **b);
int				get_to_be_pushed(t_stack **a, t_stack **b);
int				pos_2b(t_stack **b, int num, int index);
int				ft_contains(char *s, char c);
int				ft_is_number(char *s);
int				ft_out_of_int_range(const char *str);
void			check_args_err(int argc, char **argv);
char			**check_env_args(int argc, char **arge);
#endif
