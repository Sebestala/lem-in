/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 20:37:53 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/18 16:44:41 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/uio.h>
# include <limits.h>
# define BUFF_SIZE 800
# include "libft.h"

int					get_next_line(const int fd, char **line);

#endif
