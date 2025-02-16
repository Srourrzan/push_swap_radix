/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:14:19 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 12:31:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
