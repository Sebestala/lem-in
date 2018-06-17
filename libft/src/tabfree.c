/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:20:43 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/27 21:12:46 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		tabfree(char ***tab)
{
	int		i;
	int		j;

	if (tab == NULL || tab[0] == NULL)
		return ;
	i = 0;
	j = 0;
	while (tab[0][i])
	{
		if (tab[0][i] != NULL)
		{
			free(tab[0][i]);
			tab[0][i] = NULL;
		}
		i++;
	}
	free(*tab);
	*tab = NULL;
}
