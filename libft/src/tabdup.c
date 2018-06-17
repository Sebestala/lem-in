/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:25:38 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/08 19:19:54 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tabdup(char **tab)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	while (tab[i])
		i++;
	if (!(copy = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	copy[i] = NULL;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (!(copy[i] = (char *)malloc(sizeof(char) * (j + 1))))
			return (NULL);
		j = -1;
		while (tab[i][++j])
			copy[i][j] = tab[i][j];
		copy[i][j] = '\0';
		i++;
	}
	return (copy);
}
