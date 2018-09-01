/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:45:31 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/17 14:50:01 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void 	print_color(char *name, char *color)
{
	ft_putstr(color);
	ft_putstr(name);
	ft_putstr(RESET);
}

void print_color_background(char *name, char *color, char *background)
{
	ft_putstr(background);
	ft_putstr(color);
	ft_putstr(name);
	ft_putstr(RESET);
}
int 	get_color_code(struct stat stats)
{
	if (S_ISDIR(stats.st_mode) == 1)
		return (DIR_COLOR);
	else if (S_ISCHR(stats.st_mode) == 1)
		return (CHARAC_SPECIAL_COLOR);
	else if (S_ISBLK(stats.st_mode) == 1)
		return (BLOCK_COLOR);
	else if (S_ISFIFO(stats.st_mode) ==1)
		return (FIFO_COLOR);
	else if (S_ISLNK(stats.st_mode) == 1)
		return (LNK_COLOR);
	else if (S_ISSOCK(stats.st_mode) == 1)
		return (SOCKET_COLOR);
	else if (S_ISREG(stats.st_mode) == 1 && (stats.st_mode & S_IRUSR))
		return (EXEC_COLOR);
	return (0);
}

void	colors(char *name, struct stat stats)
{
	int color;

	color = get_color_code(stats);
	if (color == DIR_COLOR)
		print_color(name, CYAN);
	else if (color == CHARAC_SPECIAL_COLOR)
		print_color_background(name, BLUE, BK_YELLOW);
	else if (color == BLOCK_COLOR)
		print_color_background(name, BLUE, BK_CYAN);
	else if (color == FIFO_COLOR)
		print_color_background(name, RED, BK_GREEN);
	else if (color == LNK_COLOR)
		print_color(name, PURPLE);
	else if (color == SOCKET_COLOR)
		print_color_background(name, PURPLE, BLUE);
	else if (color == EXEC_COLOR)
		print_color(name, RED);	
}

void 	print_list_no_opts(S_list *list)
{
	args_node *arg;

	arg = list->head;
	while (arg)
	{
		//ft_putstr(arg->content);
		colors(arg->content, arg->stats);
		ft_putchar('\n');
		arg = arg->next;
	}
}

void	print_list(S_list *list, options opts, char *dir_name)
{
	args_node	*arg;
	int 		max_len;

	arg = list->head;
	if (opts.l == 1)
		option_l(list, opts, dir_name);
	else
	{
		if (opts.i == 1)
			max_len = get_inode(list);
		while (arg)
		{
			if (opts.i == 1)
				option_i(arg, max_len);
			ft_putstr(arg->content);
			//colors(arg->content, arg->stats);
			ft_putchar('\n');
			arg = arg->next;
		}
	}
	/*if (opts != NULL)
		free(opts);*/
}

void	print_does_not_exist_list(S_list *no_list)
{
	args_node	*elem;

	elem = no_list->head;
	while (elem)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(elem->content);
		ft_putstr(": No such file or directory");
		ft_putchar('\n');
		elem = elem->next;
	}
	//free(list);
}