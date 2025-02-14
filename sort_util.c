/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/13 23:57:15 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_list(t_info **a_info, t_list **b, int fd)
{
	if (!ft_ascend_check(&(*a_info)->head))
	{
		if ((*a_info)->size <= 3)
			p;
		else if ((*a_info)->size <= 5)
			p;
		else
			p;
	}
}

int	ft_sort_list_ascend(t_list **a, t_list **b, int counter, int fd)
{
	counter = ft_ascend_reverse_rotate(a, b, counter, fd);
	counter = ft_ascend_swap(a, b, counter, fd);
	if (!ft_ascend_check(a))
	{
		counter = ft_ascend_push(a, b, counter, fd);
		counter = ft_decscend_swap(a, b, counter, fd);
	}
	return counter;
}

int	ft_sort_list_descend(t_list **b, t_list **a, int counter, int fd)
{
	if (*b)
	{
		counter = ft_dascend_rotate(a, b, counter, fd);
		counter = ft_decscend_swap(a, b, counter, fd);
		counter = ft_descend_push(a, b, counter, fd);
		counter = ft_ascend_swap(a, b, counter, fd);
	}
	return counter;
}

int	ft_ascend_check(t_list **a)
{
	t_list	*curr;

	curr = *a;
	if (curr == NULL )
		return (1);
	if (!curr->next)
		return (1);
	while (curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	ft_descend_check(t_list **b)
{
	t_list	*curr;

	curr = *b;
	if (curr == NULL )
		return (1);
	if (!curr->next)
		return (1);
	while (curr->next != NULL)
	{
		if (curr->content < curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}
