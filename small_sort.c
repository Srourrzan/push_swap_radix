/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:02:00 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/14 18:06:39 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_two(t_info *a_info)
{
    swap(&(a_info->head));
    ft_putstr("sa\n", 1);
    ft_display_stack(&(a_info->head), 'a', 1);
}

void	ft_three_sort(t_info *a_info)
{
	if (a_info->size == 2)
		ft_sort_two(a_info);
}