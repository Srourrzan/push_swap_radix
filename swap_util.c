/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:49:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 12:44:43 by rsrour           ###   ########.fr       */
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
