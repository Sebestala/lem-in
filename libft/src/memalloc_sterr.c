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

//	if (size < 4294967295)
	{
		if ((mall = (void *)malloc((size + 1) * sizeof(void))) == 0)
		{
			ft_putstr_fd(2, "Error : dynamic allocation problem in ");
			exit_str(str);
		}
		ft_bzero(mall, size + 1);
	}
/*	else
	{
		ft_putstr_fd(2, "Error : problem size for dynamic allocation in ");
		exit_str(str);
	}
*/	return (mall);
}
