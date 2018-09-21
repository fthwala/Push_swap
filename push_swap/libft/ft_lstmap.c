/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 13:11:11 by fthwala           #+#    #+#             */
/*   Updated: 2017/11/28 12:41:04 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*sorting;

	if (lst)
	{
		sorting = f(lst);
		sorting->next = ft_lstmap(lst->next, f);
		return (sorting);
	}
	return (NULL);
}
