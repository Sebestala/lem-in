/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_printf2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:02:50 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/31 20:13:05 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		rainbow_line(int i)
{
	int	j;

	j = 0;
	while (j < 15)
	{
		rainbow(i + j);
		write(1, "____", 4);
		j++;
	}
	rainbow(-1);
}

void			man_printf(void)
{
	int	i;
	int	tmp;

	i = 400;
	while (i > 1)
	{
		rainbow_line(i);
		print_man();
		rainbow_line(i);
		man_printf2();
		tmp = 99999999;
		while (tmp > -500000)
			tmp--;
		write(1, "\033[2J", 5);
		i--;
	}
}
