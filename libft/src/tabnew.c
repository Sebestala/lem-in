/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:14:03 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/27 20:59:14 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tabnew(int x, int y)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (y + 1))))
		return (NULL);
	while (i < y)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (x + 1))))
			return (NULL);
		j = 0;
		while (j <= x)
			tab[i][j++] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
