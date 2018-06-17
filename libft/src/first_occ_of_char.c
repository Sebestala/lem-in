/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_occ_of_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:49:50 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/23 17:49:52 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		first_occ_of_char(char *str, char c)
{
	int				i;

	i = 0;
	if (!str)
		return (-1);
	if (str[i] == c)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
		if (c == '\0' && str[i] == '\0')
			return (i);
	}
	return (-1);
}
