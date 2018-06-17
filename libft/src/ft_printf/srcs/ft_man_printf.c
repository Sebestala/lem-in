/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:01:26 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/31 20:15:55 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			print_man(void)
{
	ft_putstr("\n\033[1;31;40m\n");
	ft_putstr(" ____    ____    _   _   _   _____   _____ ");
	ft_putstr("\033[33m   *    .   +  .\n\033[33m");
	ft_putstr("|  _ \\  |  _ \\  |_| | \\ | | |_   _| |  ___|");
	ft_putstr("\033[33m +      -\n\033[32m");
	ft_putstr("| | | | | | | |  _  |  \\| |   | |   | |  ");
	ft_putstr("\033[33m .  -  @   *\n\033[37m");
	ft_putstr("| |_| | | |_| | | | |   | |   | |   | |__ ");
	ft_putstr("\033[33m @  *   +\n\033[36m");
	ft_putstr("|  __/  |  _ /  | | | |   |   | |   |  __|");
	ft_putstr("\033[33m + .\n\033[34m");
	ft_putstr("| |     | |\\ \\  | | | |\\  |   | |   | |");
	ft_putstr("\033[33m .   \n\033[35m");
	ft_putstr("|_|     |_| |_| |_| |_| |_|   |_|   |_|");
	ft_putstr("\033[33m     \n\033[0m\n");
	ft_putstr("The usage is like printf function.\nYou can also write ");
	ft_putstr("in a file directory with {-FD=%d}.\n\nYou can put colors or ");
	ft_putstr("differents syntaxes with thoses flags:\n-PINK -CYAN -GREY -RED");
	ft_putstr(" -BLACK -GREEN -YELLOW -BLUE -LIGHT \n-SHADOW -DARK -ITALIC ");
	ft_putstr("-LINE -REVERSE.\n\nYou can color the background too with:\n");
	ft_putstr("-BPINK -BCYAN -BGREY -BRED -BBLACK -BGREEN -BYELLOW -BBLUE.\n");
	ft_putstr("\nYou can moove the cursor location with:\n-UP -DOWN -LEFT -RI");
	ft_putstr("GHT -SAVE -LOAD\n\nOr delete page/line: -DELPAGE -DELLINE\n");
	ft_putstr("\nFor use the man: -MAN.\n\nExamples: {-BYELLOW-BLACK-LIGHT}\n");
	ft_putstr("\nBonus: Wildcards, Binary, Man, Fd, Colors, Syntaxes, Fun.\n");
}

static char		**set_fg_color(void)
{
	char	**fg_color;

	if (!(fg_color = (char **)malloc(16 * sizeof(char *))))
		return (NULL);
	fg_color[0] = "\033[m";
	fg_color[1] = "\033[1m";
	fg_color[2] = "\033[2m";
	fg_color[3] = "\033[1;2m";
	fg_color[4] = "\033[3m";
	fg_color[6] = "\033[4m";
	fg_color[5] = "\033[7m";
	fg_color[7] = "\033[30m";
	fg_color[8] = "\033[31m";
	fg_color[9] = "\033[32m";
	fg_color[10] = "\033[33m";
	fg_color[11] = "\033[34m";
	fg_color[12] = "\033[35m";
	fg_color[13] = "\033[36m";
	fg_color[14] = "\033[37m";
	fg_color[15] = NULL;
	return (fg_color);
}

static char		**set_bg_color(void)
{
	char	**bg_color;

	if (!(bg_color = (char **)malloc(9 * sizeof(char *))))
		return (NULL);
	bg_color[0] = "\033[40m";
	bg_color[1] = "\033[41m";
	bg_color[2] = "\033[42m";
	bg_color[3] = "\033[43m";
	bg_color[4] = "\033[44m";
	bg_color[5] = "\033[45m";
	bg_color[6] = "\033[46m";
	bg_color[7] = "\033[47m";
	bg_color[8] = NULL;
	return (bg_color);
}

static char		**set_first_column(void)
{
	char	**first_column;

	if (!(first_column = (char **)malloc(16 * sizeof(char *))))
		return (NULL);
	first_column[0] = " FG \\   ";
	first_column[1] = "Light   ";
	first_column[2] = "Dark    ";
	first_column[3] = "Shadow  ";
	first_column[4] = "Italic  ";
	first_column[6] = "Line    ";
	first_column[5] = "Reverse ";
	first_column[7] = "Black   ";
	first_column[8] = "Red     ";
	first_column[9] = "Green   ";
	first_column[10] = "Yellow  ";
	first_column[11] = "Blue    ";
	first_column[12] = "Pink    ";
	first_column[13] = "Cyan    ";
	first_column[14] = "Grey    ";
	first_column[15] = NULL;
	return (first_column);
}

void			man_printf2(void)
{
	char	**fg_color;
	char	**bg_color;
	char	**first_column;
	int		i;
	int		j;

	fg_color = set_fg_color();
	bg_color = set_bg_color();
	first_column = set_first_column();
	i = 0;
	ft_putstr("\n\033[0m   \\ BG  ");
	ft_putstr("Black Red  Green Yellow Blue  Pink  Cyan  Grey \n\033[0m");
	while (first_column[i])
	{
		j = 0;
		ft_putstr(first_column[i]);
		ft_putstr(fg_color[i]);
		while (bg_color[j])
		{
			ft_putstr(bg_color[j++]);
			ft_putstr(" Test ");
		}
		ft_putstr("\033[0m\n");
		i++;
	}
}
