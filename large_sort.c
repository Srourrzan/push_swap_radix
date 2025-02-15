/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 07:04:11 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 02:34:43 by rsrour           ###   ########.fr       */
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

static  int     ft_max_index(t_list **root)
{
    t_list      *curr;
    int         max;

    curr = *root;
    max = curr->index;
    while(curr != NULL)
    {
        if (curr->index > max)
            max = curr->index;
        curr = curr->next;
    }
    return (max);
}

static  int     ft_max_bits(int index)
{
    int     bits;

    bits = 0;
    while ((index - 1) >> bits)
        bits++;
    return (bits);
}

void    ft_large_sort(t_info *a_info, t_list **b)
{
    int     max_bits;
    int     max_index;
    //int     iter;

    ft_assign_index(&(a_info->head));
    max_index = ft_max_index(&(a_info->head));
    max_bits = ft_max_bits(max_index);
    printf("max bit = %d\n", max_bits);
    push(&(a_info->head), b);
}
