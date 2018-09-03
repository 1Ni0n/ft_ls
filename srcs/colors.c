/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:10:59 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/03 13:11:37 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	print_color(char *name, char *color)
{
	ft_putstr(color);
	ft_putstr(name);
	ft_putstr(RESET);
}

void	print_color_background(char *name, char *color, char *background)
{
	ft_putstr(background);
	ft_putstr(color);
	ft_putstr(name);
	ft_putstr(RESET);
}

int		get_color_code(struct stat stats)
{
	if (S_ISDIR(stats.st_mode) == 1)
		return (DIR_COLOR);
	else if (S_ISCHR(stats.st_mode) == 1)
		return (CHARAC_SPECIAL_COLOR);
	else if (S_ISBLK(stats.st_mode) == 1)
		return (BLOCK_COLOR);
	else if (S_ISFIFO(stats.st_mode) == 1)
		return (FIFO_COLOR);
	else if (S_ISLNK(stats.st_mode) == 1)
		return (LNK_COLOR);
	else if (S_ISSOCK(stats.st_mode) == 1)
		return (SOCKET_COLOR);
	else if (S_ISREG(stats.st_mode) == 1 && (stats.st_mode & S_IXUSR))
		return (EXEC_COLOR);
	return (0);
}

void	colors(t_args_node *elem, struct stat stats)
{
	int color;

	if (!elem->path)
		lstat(elem->content, &stats);
	else
		lstat(elem->path, &stats);
	color = get_color_code(stats);
	if (color == DIR_COLOR)
		print_color(elem->content, B_CYAN);
	else if (color == CHARAC_SPECIAL_COLOR)
		print_color_background(elem->content, BLUE, BK_YELLOW);
	else if (color == BLOCK_COLOR)
		print_color_background(elem->content, BLUE, BK_CYAN);
	else if (color == FIFO_COLOR)
		print_color_background(elem->content, RED, BK_GREEN);
	else if (color == LNK_COLOR)
		print_color(elem->content, PURPLE);
	else if (color == SOCKET_COLOR)
		print_color_background(elem->content, PURPLE, BLUE);
	else if (color == EXEC_COLOR)
		print_color(elem->content, RED);
	else
		print_color(elem->content, RESET);
}
