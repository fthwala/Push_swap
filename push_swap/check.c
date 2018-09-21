/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 01:18:55 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/29 12:18:32 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_args_err(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	if (ft_strequ(*argv, "") || !valid_args(argc - 1, argv))
	{
		ft_putendl("Error");
		exit(1);
	}
}

char		**check_env_args(int argc, char **argv)
{
	if (argc == 2 && ft_contains(argv[0], ' '))
		argv = ft_strsplit(argv[0], ' ');
	return (argv);
}
