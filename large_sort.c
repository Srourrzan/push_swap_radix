/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 07:04:11 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 12:29:45 by codespace        ###   ########.fr       */
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
}

static  int     ft_max_bits(int index)
{
    int     bits;

    bits = 0;
    while ((index - 1) >> bits)
        bits++;
    return (bits);
}

static  void    ft_radix_sort_lsd(t_info *a_info, t_list **b, int bit)
{
    int     size;
    int     iter;
    int     num;

    size = a_info->size;
    iter = 0;
    while (iter < size)
    {
        num = a_info->head->index;
        if ((num >> bit) & 1)
        {
            rotate(&(a_info->head));
            ft_putstr("ra\n", 1);
        }
        else
            ft_ascend_push(&(a_info->head), b, 1);
        iter++;
    }
}

void    ft_large_sort(t_info *a_info, t_list **b)
{
    int     max_bits;
    int     max_index;
    int     iter;

    ft_assign_index(&(a_info->head));
    max_index = a_info->size - 1;
    max_bits = ft_max_bits(max_index);
    iter = 0;
    while (iter < max_bits)
    {
        ft_radix_sort_lsd(a_info, b, iter);
        while((*b) != NULL)
            ft_descend_push(&(a_info->head), b, 1);
        iter++;
    }
}
