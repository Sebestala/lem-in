/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:19:34 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/21 18:23:00 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *temp_s;
	unsigned char *temp_d;

	temp_s = (unsigned char *)src;
	temp_d = (unsigned char *)dst;
	if (dst > src)
	{
		while (len--)
			temp_d[len] = temp_s[len];
		return (temp_d);
	}
	ft_memcpy(temp_d, temp_s, len);
	return (temp_d);
}
