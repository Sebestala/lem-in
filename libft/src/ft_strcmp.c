/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:11:04 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/17 15:35:52 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				j;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 | !s2)
		exit_str("Error : in ft_strcmp");
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	j = 0;
	while (str1[i] || str2[i])
	{
		j = str1[i] - str2[i];
		i++;
		if (j != 0)
			return (j);
	}
	return (0);
}
