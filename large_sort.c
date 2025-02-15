/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 07:04:11 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 01:55:53 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_assign_index(t_list **root)
{
    t_list  *curr;
    t_list  *temp;
    int     index;

    curr = *root;
    while (curr)
    {
        index = 0;
        temp = *root;
        while (temp)
        {
            if (curr->content > temp->content)
                index++;
            temp = temp->next;
        }
        curr->index = index;
        curr = curr->next;
    }
    curr = *root;
    //create ft_index_display to display the indeces, and create a
    // file for std display and a file for stack display
    while (curr != NULL)
	{
		ft_putnbr(curr->content, 1);
        ft_putstr(" : ", 1);
        ft_putnbr(curr->index, 1);
		ft_putchar('\n', 1);
		curr = curr->next;
	}
}

void    ft_large_sort(t_info *a_info, t_list **b)
{
    // int     max_bits;
    // int     iter;

    ft_assign_index(&(a_info->head));
    push(&(a_info->head), b);
}
