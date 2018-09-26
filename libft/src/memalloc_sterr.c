/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc_sterr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:28:10 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/17 19:35:45 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memalloc_sterr(size_t size, char *str)
{
	void	*mall;
	size_t	i;

	if ((mall = (void *)malloc((size + 1) * sizeof(void))) == 0)
	{
		ft_putstr_fd(2, "Error : dynamic allocation problem in ");
		exit_str(str);
	}
	i = 0;
	while (i < size + 1)
	{
		((char *)mall)[i] = '\0';
		i++;
	}
	return (mall);
}
