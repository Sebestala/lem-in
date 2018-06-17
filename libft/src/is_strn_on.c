/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_strn_on.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:02:34 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/30 20:09:17 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_strn_on(char *str1, char *str2, int len)
{
	int		i;
	int		j;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (str1[i] && i < len)
	{
		j = 0;
		while (str1[i] == str2[j] && i < len)
		{
			i++;
			j++;
			if (!str2[j])
				return (1);
		}
		i++;
	}
	return (0);
}
