/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/15 07:09:54 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_info	*info_a;
	//t_info	*info_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd > 0)
	{
		ft_fill_stack(&stack_a, argv, argc, fd);
		info_a = ft_stack_info(stack_a);
		ft_sort_list(info_a, &stack_b, fd);
		ft_display_stacks(&(info_a->head), &stack_b, 1);
	}
	else
		printf("failed: file descriptor: %d\n", fd);
	close(fd);
	delete_list(&stack_a);
	free(info_a);
	//delete_list(&stack_b);
	return (0);
}
