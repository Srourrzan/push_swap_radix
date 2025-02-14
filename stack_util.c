/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:49:02 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/14 23:32:12 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Main Push Swap RULES:
 * "push_swap" program should take as an argument the stack 'a' formatted as a list of integers.
 * The first argument should be at the top of the stack.
*/

#include "push_swap.h"

void    ft_fill_stack(t_list **root, char **numbers, int argc, int fd)
{
    int     iter;
    int     number;
    char    **dup_num;
    int     dup_iter;

    iter = 1;
    number = 0;
    dup_iter = 0;
    dup_num = malloc(sizeof(char *) * (argc + 1));
    if (!dup_num)
        ft_exit(root, NULL, 3);
    ft_init_array(dup_num, argc + 1);
    while(numbers[iter] != NULL)
    {
        if (ft_is_number(numbers[iter]) && !ft_is_dup(dup_num, numbers[iter]))
        {
            dup_num[dup_iter++] = ft_strdup(numbers[iter]);
            number = ft_atoi(numbers[iter++], root, dup_num);
            insert_node_back(root, number);
        }
        else
            ft_exit(root, dup_num, 1);
    }
    ft_free_str_array(dup_num);
    ft_display_stack(root, 'a', fd);
}


int     ft_is_dup(char **dup_num, char *number)
{
    int     iter_arr;
    int     cmp;
    
    iter_arr = 0;
    cmp = 0;
    while(dup_num[iter_arr] != NULL)
    {
        cmp = ft_strcmp(dup_num[iter_arr], number);
        if (cmp == 0)
            return (1);
        iter_arr++;
    }
    return (0);
}

int     ft_is_number(char *src)
{
    int     iter;

    iter = 0;
    if (src[iter] == '+' || src[iter] == '-')
        iter++;
    while(src[iter])
    {
        if (src [iter] < '0' || src[iter] > '9')
            return (0);
        iter++;
    }
    return (1);
}
int    ft_find_min_index(t_list **root)
{
    t_list  *curr;
    int     min;
    int     iter;
    int     index;

    curr = *root;
    min = curr->content;
    index = 0;
    iter = 0;
    while(curr)
    {
        if (curr->content < min)
        {
            min = curr->content;
            index = iter;
        }
        iter++;
        curr = curr->next;
    }
    return (index);
}

void    ft_move_min_to_top(t_info *a_info, int size)
{
    int     index;

    index = ft_find_min_index(&(a_info->head));
    printf("min valud pos = %d, size = %d\n", index, size);
}