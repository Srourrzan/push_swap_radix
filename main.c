/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/14 17:44:22 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_info	*info_a;
	//t_info	*info_b;
	int		counter;
	
	counter = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);
	int	fd_t = open("trials.txt", O_WRONLY | O_APPEND);
	if (fd > 0)
	{
		ft_fill_stack(&stack_a, argv, argc, fd);
		info_a = ft_stack_info(stack_a);
		ft_sort_list(info_a, &stack_b, fd);
		printf("info_a->size = %d\n", info_a->size);
		printf("number of ops: %d\n", counter);
	}
	else
		printf("failed: file descriptor: %d\n", fd);
	if (fd_t)
	{
		ft_putstr(" argc: ", fd_t);
		ft_putnbr(argc-1, fd_t);
		ft_putstr(" operations: ", fd_t);
		ft_putnbr(counter, fd_t);
		ft_putstr("\n", fd_t);
	}
	close(fd);
	close(fd_t);
	delete_list(&stack_a);
	delete_list(&stack_b);
	return (0);
}
