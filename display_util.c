/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:14:19 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/07 21:11:48 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stack(t_list **root, char name, int fd)
{
	t_list	*curr;

	curr = *root;
	while (curr != NULL)
	{
		ft_putnbr(curr->content, fd);
		ft_putchar('\n', fd);
		curr = curr->next;
	}
	ft_putchar('_', fd);
	ft_putchar('\n', fd);
	ft_putchar(name, fd);
	ft_putchar('\n', fd);
}

void	ft_putchar(char ch, int fd)
{
	write(fd, &ch, 1);
}

void	ft_putstr(char *src, int fd)
{
	int	iter;

	iter = 0;
	while (src[iter])
	{
		ft_putchar(src[iter], fd);
		iter++;
	}
}

void	ft_display_stacks(t_list **a, t_list **b, int fd)
{
	t_list	*curr_a;
	t_list	*curr_b;
	t_list	*temp;

	curr_a = *a;
	curr_b = *b;
	temp = curr_a;
	while (curr_a != NULL || curr_b != NULL)
	{
		if (curr_a)
		{
			ft_putnbr(curr_a->content, fd);
			temp = curr_a;
			curr_a = curr_a->next;
		}
		ft_correct_space_display(temp, fd);
		if (curr_b)
		{
			ft_putnbr(curr_b->content, fd);
			curr_b = curr_b->next;
		}
		ft_putstr("\n", fd);
	}
	ft_putstr("___________   ___________\n", fd);
	ft_putstr("a             b\n", fd);
}

void	ft_putnbr(int nbr, int fd)
{
	char	res;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_putstr("-2147483648", fd);
			return ;
		}
		ft_putchar('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, fd);
	res = nbr % 10 + '0';
	ft_putchar(res, fd);
}

void	ft_correct_space_display(t_list *node, int fd)
{
	int		len;
	int		iter;
	static int		snumber;
	int		number;
	
	len = 0;
	iter = 0;
	if (node)
	{
		number = node->content;
		if (snumber != node->content || (node->next != NULL))
		{
			snumber = number;
			if (number < 0)
			{
				number = number * -1;
				len++;
			}
			while (number > 0)
			{
				number /= 10;
				len++;
			}
		}
	}
	while (iter < (13 - len))
	{
		ft_putstr(" ", fd);
		iter++;
	}
}
