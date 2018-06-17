/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:11:17 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/25 18:23:22 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*copy;
	unsigned char	occ;

	i = 0;
	copy = (unsigned char *)s;
	occ = c;
	while (i < n)
	{
		if (copy[i] == occ)
			return (&copy[i]);
		i++;
	}
	return (NULL);
}
