/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 16:37:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_info	*info_a;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_fill_stack(&stack_a, argv, argc);
	info_a = ft_stack_info(stack_a);
	if (!info_a)
    {
        delete_list(&stack_a);
        ft_exit(&stack_a, NULL, 3);  // Handle allocation failure
    }
	ft_sort_list(info_a, &stack_b);
	free(info_a);
	delete_list(&stack_a);
	delete_list(&stack_b);
	return (0);
}
