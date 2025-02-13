/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:49:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/07 22:04:41 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * swap function is responsible for doing the following two operations:
 *  - sa (swap a): Swap the first 2 elements at the top of stack a.
 *  - sb (swap b): Swap the first 2 elements at the top of stack b.
 *      Do nothing if there is only one or no elements
 */
void	swap(t_list **root)
{
	t_list	*head;
	t_list	*second;

	if (!root || !(*root) || (*root)->next == NULL)
		return ;
	head = *root;
	second = head->next;
	head->next = second->next;
	second->next = head;
	*root = second;
}

/*
 *  - ss: sa and sb at the same time
 */
void	ss(t_list **root_a, t_list **root_b)
{
	swap(root_a);
	swap(root_b);
}

int    ft_ascend_swap(t_list **a, t_list **b, int counter, int fd)
{
	t_status	*status;

	status = malloc(sizeof(t_status));
	if (!status)
		return (counter);
	status->status_1 = ((*a)->next != NULL) && ((*a)->content > (*a)->next->content);
	status->status_2 = (*b) != NULL && ((*b)->next != NULL) && ((*b)->content < (*b)->next->content);
    if(status->status_1)
	{
		if (status->status_1 && status->status_2)
		{
			ss(a, b);
			ft_putstr("ss\n", fd);
		}
		else if (status->status_1)
		{
			swap(a);
			ft_putstr("sa\n", fd);
		}
		else if (status->status_2)
		{
			swap(b);
			ft_putstr("sb\n", fd);
		}
		counter++;
		ft_display_stacks(a, b, fd);
	}
	free(status);
	return counter;
}

int		ft_decscend_swap(t_list ** a, t_list **b, int counter, int fd)
{
	t_status	*status;

	status = malloc(sizeof(status));
	if (!status)
		return (counter);
	status->status_1 = ((*b)->next != NULL) && ((*b)->content < (*b)->next->content);
	status->status_2 = ((*a) != NULL) && (*a)->next != NULL && ((*a)->content > (*a)->next->content);
	if (status->status_1 || status->status_2)
	{
		if(status->status_1 && status->status_2)
		{
			ss(a, b);
			ft_putstr("ss\n", fd);
		}
		else if (status->status_1 && !status->status_2)
		{
			swap(b);
			ft_putstr("sb\n", fd);
		}
		else if (status->status_2)
		{
			swap(a);
			ft_putstr("sa\n", fd);
		}
		counter++;
		ft_display_stacks(a, b, fd);
	}
	free(status);
	return counter;
}
