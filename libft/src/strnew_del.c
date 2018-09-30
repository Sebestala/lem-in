/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 16:22:36 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/29 16:24:55 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*strnew_del(size_t size, char *str)
{
	int		i;

	i = 0;
	ft_strdel(&str);
	str = NULL;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i <= (int)size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
