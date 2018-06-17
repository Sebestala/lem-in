/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:30:24 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/31 19:55:03 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_print		strcat_buff_color(char *str, t_print res)
{
	int		i;

	i = 0;
	if (res.length >= BUFF_SIZE - 10)
		res = ft_clean(res);
	while (str[i])
	{
		if (res.length == BUFF_SIZE - 1)
			res = ft_clean(res);
		res.buf[res.length++] = str[i++];
	}
	return (res);
}

static t_print		check_option3(char *str, t_print res, int len)
{
	if (is_strn_on(str, "-DELLINE", len))
		res = strcat_buff_color("\033[K", res);
	if (is_strn_on(str, "-DELPAGE", len))
		res = strcat_buff_color("\033[2J", res);
	if (is_strn_on(str, "-UP", len))
		res = strcat_buff_color("\033[1A", res);
	if (is_strn_on(str, "-DOWN", len))
		res = strcat_buff_color("\033[1B", res);
	if (is_strn_on(str, "-LEFT", len))
		res = strcat_buff_color("\033[1D", res);
	if (is_strn_on(str, "-RIGHT", len))
		res = strcat_buff_color("\033[1C", res);
	if (is_strn_on(str, "-SAVE", len))
		res = strcat_buff_color("\033[s", res);
	if (is_strn_on(str, "-LOAD", len))
		res = strcat_buff_color("\033[u", res);
	return (res);
}

static t_print		check_option2(char *str, t_print res, int len)
{
	if (is_strn_on(str, "-BPINK", len))
		res = strcat_buff_color("\033[45m", res);
	if (is_strn_on(str, "-CYAN", len))
		res = strcat_buff_color("\033[36m", res);
	if (is_strn_on(str, "-BCYAN", len))
		res = strcat_buff_color("\033[46m", res);
	if (is_strn_on(str, "-GREY", len))
		res = strcat_buff_color("\033[37m", res);
	if (is_strn_on(str, "-BGREY", len))
		res = strcat_buff_color("\033[47m", res);
	if (is_strn_on(str, "-DEFAULT", len))
		res = strcat_buff_color("\033[0m", res);
	if (is_strn_on(str, "-LIGHT", len))
		res = strcat_buff_color("\033[1m", res);
	if (is_strn_on(str, "-DARK", len))
		res = strcat_buff_color("\033[2m", res);
	if (is_strn_on(str, "-SHADOW", len))
		res = strcat_buff_color("\033[1;2m", res);
	if (is_strn_on(str, "-ITALIC", len))
		res = strcat_buff_color("\033[3m", res);
	if (is_strn_on(str, "-LINE", len))
		res = strcat_buff_color("\033[4m", res);
	if (is_strn_on(str, "-REVERSE", len))
		res = strcat_buff_color("\033[7m", res);
	return (res);
}

static t_print		check_option(char *str, t_print res, int len)
{
	if (is_strn_on(str, "-RED", len))
		res = strcat_buff_color("\033[31m", res);
	if (is_strn_on(str, "-BRED", len))
		res = strcat_buff_color("\033[41m", res);
	if (is_strn_on(str, "-BLACK", len))
		res = strcat_buff_color("\033[30m", res);
	if (is_strn_on(str, "-BBLACK", len))
		res = strcat_buff_color("\033[40m", res);
	if (is_strn_on(str, "-GREEN", len))
		res = strcat_buff_color("\033[32m", res);
	if (is_strn_on(str, "-BGREEN", len))
		res = strcat_buff_color("\033[42m", res);
	if (is_strn_on(str, "-YELLOW", len))
		res = strcat_buff_color("\033[33m", res);
	if (is_strn_on(str, "-BYELLOW", len))
		res = strcat_buff_color("\033[43m", res);
	if (is_strn_on(str, "-BLUE", len))
		res = strcat_buff_color("\033[34m", res);
	if (is_strn_on(str, "-BBLUE", len))
		res = strcat_buff_color("\033[44m", res);
	if (is_strn_on(str, "-PINK", len))
		res = strcat_buff_color("\033[35m", res);
	res = check_option2(str, res, len);
	res = check_option3(str, res, len);
	return (res);
}

t_print				put_syntax(char *str, t_print res, va_list ap)
{
	int		len;
	int		va;

	len = 0;
	while (str[len] && str[len] != '}')
		len++;
	if (str[len] != '}')
		return (res);
	if (is_strn_on(str, "-MAN", len))
		man_printf();
	if (is_strn_on(str, "-FD=%d", len))
	{
		va = va_arg(ap, int);
		if (va)
			res.fd = va;
	}
	res = check_option(str, res, len);
	res.k = res.k + len + 1;
	return (res);
}
