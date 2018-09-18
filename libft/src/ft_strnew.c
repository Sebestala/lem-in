/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:35:00 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/17 19:33:59 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
//	if (size < 4294967295)
	{
		if (!(str = (char *)malloc((size + 1) * sizeof(char))))
			return (NULL);
		while (i <= (int)size)
		{
			str[i] = '\0';
			i++;
		}
	}
//	else
//		return (NULL);
	return (str);
}
