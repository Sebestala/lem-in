/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_end_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:20:53 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/05 20:31:36 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		atoi_end_index(char **str)
{
	int		i;
	int		res;
	int		sign;

	if (!*str || str[0][0] == '\0')
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while (str[0][i] && (str[0][i] < '0' || str[0][i] > '9'))
	{
		if (str[0][i + 1] && str[0][i] == '-' &&
				(str[0][i + 1] >= '0' && str[0][i + 1] <= '9'))
			sign = -1;
		i++;
	}
	while (str[0][i] != '\0' && str[0][i] >= '0' && str[0][i] <= '9')
	{
		res *= 10;
		res += (str[0][i] - 48);
		i++;
	}
	*str = &str[0][i];
	return (res * sign);
}
