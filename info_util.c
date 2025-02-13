/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:58:02 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/13 21:07:18 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info  *ft_stack_info(t_list *stack)
{
    t_info  *info;
    int     size;

    size =len_list(&stack);
    info = malloc(sizeof(t_info));
    if (!info)
        return (NULL);
    info->head = stack;
    info->size = size;
    return (info);
}
