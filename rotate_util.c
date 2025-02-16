/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:35:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 12:45:10 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate function is responsible for doing the following two operations:
 * - ra (rotate a): Shift up all elements of stack a by 1.
 *                  The first element becomes the last one.
 * - rb (rotate b): Shift up all elements of stack b by 1.
 *                  The first element becomes the last one.
 */

void	rotate(t_list **root)
{
	t_list	*temp;
	t_list	*curr;

	if (!root || !(*root) || !((*root)->next))
		return ;
	curr = *root;
	temp = *root;
	*root = (*root)->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
}

/* rr: ra and rb at the same time */

void	rr(t_list **root_a, t_list **root_b)
{
	rotate(root_a);
	rotate(root_b);
}

/* reverse_rotate is responsible for doing the following two operations:
 * - rra (reverse rotate a): Shift down all elements of stack a by 1.
 *                  The last element becomes the first one.
 * - rrb (reverse rotate b): Shift down all elements of stack b by 1.
 *                  The last element becomes the first one.
 */
void	reverse_rotate(t_list **root)
{
	t_list	*curr;
	t_list	*next_to_curr;

	if (!root || !(*root) || (*root)->next == NULL)
		return ;
	curr = *root;
	next_to_curr = curr->next;
	while (next_to_curr->next != NULL)
	{
		curr = curr->next;
		next_to_curr = next_to_curr->next;
	}
	curr->next = NULL;
	next_to_curr->next = *root;
	*root = next_to_curr;
}

/* rrr: rra and rrb at the same time */

void	rrr(t_list **root_a, t_list **root_b)
{
	reverse_rotate(root_a);
	reverse_rotate(root_b);
}
