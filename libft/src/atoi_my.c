/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_my.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 21:47:24 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/11 23:01:26 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		atoi_my(char *str)
{
	int		i;
	int		res;
	int		sign;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while (str && (str[i] < '0' || str[i] > '9'))
	{
		if (str[i + 1] && str[i] == '-' &&
				(str[i + 1] >= '0' && str[i + 1] <= '9'))
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * sign);
}
