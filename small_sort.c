/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:02:00 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 12:53:12 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_two(t_info *a_info)
{
    swap(&(a_info->head));
    ft_putstr("sa\n", 1);
    ft_display_stack(&(a_info->head), 'a', 1);
}

void    ft_three_stack_conditions(t_info *a_info, int n1, int n2, int n3)
{
    if (n1 < n2 && n2 > n3)
    {
        reverse_rotate(&(a_info->head));
        ft_putstr("rra\n", 1);
        if (n1 < n3)
        {
            swap(&(a_info->head));
            ft_putstr("sa\n", 1);
        }
    }
    else if (n1 > n2 && n1 > n3)
    {
        rotate(&(a_info->head));
        ft_putstr("ra\n", 1);
        if (n2 > n3)
        {
            swap(&(a_info->head));
            ft_putstr("sa\n", 1);   
        }
    }
    else if (n1 > n2 && n1 < n3)
    {
        swap(&(a_info->head));
        ft_putstr("sa\n", 1);  
    }
}

void	ft_three_sort(t_info *a_info)
{
    int     first;
    int     second;
    int     third;
    
    
	if (a_info->size == 2)
		ft_sort_two(a_info);
    else
    {
        first = a_info->head->content;
        second = a_info->head->next->content;
        third = a_info->head->next->next->content;
        ft_putstr("defined\n", 1);
        ft_three_stack_conditions(a_info, first, second, third);
    }
}

void    ft_five_sort(t_info *a_info, t_list **b)
{
    int     size;
    
    size = a_info->size;
    while (a_info->size > 3)
    {
        ft_move_min_to_top(a_info, size);
        ft_ascend_push(&(a_info->head), b, 1);
        a_info->size = len_list(&(a_info->head));
    }
    ft_three_sort(a_info);
    ft_display_stacks(&(a_info->head), b, 1);
    while(*b)
        ft_descend_push(b, &(a_info->head), 1);
    ft_display_stacks(&(a_info->head), b, 1);
}
