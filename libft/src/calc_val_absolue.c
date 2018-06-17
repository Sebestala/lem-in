/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_val_absolue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 21:50:04 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/30 17:01:56 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_val_absolue2(int nb1, char op, int nb2, int res)
{
	if (op == '/')
	{
		if (nb2 == '0')
		{
			write(1, "Division by 0 impossible.", 25);
			return (0);
		}
		res = nb1 / nb2;
	}
	if (op == '%')
	{
		if (nb2 == '0')
		{
			write(1, "Modulo by 0 impossible.", 23);
			return (0);
		}
		res = nb1 % nb2;
	}
	return (res);
}

int			calc_val_absolue(int nb1, char op, int nb2)
{
	int		res;

	res = 0;
	if (!op)
		return (0);
	if (nb1 < 0)
		nb1 *= -1;
	if (nb2 < 0)
		nb2 *= -1;
	if (op == '+')
		res = nb1 + nb2;
	if (op == '-')
		res = nb1 - nb2;
	if (op == '*')
		res = nb1 * nb2;
	if (op == '/' || op == '%')
		res = calc_val_absolue2(nb1, op, nb2, res);
	if (res < 0)
		res *= -1;
	return (res);
}
