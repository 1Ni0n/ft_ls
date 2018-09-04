/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l_printing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:19:00 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/04 12:43:15 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	print_hardlinks(struct stat stats, size_t longest_hardlink)
{
	size_t	whitespaces;

	whitespaces = ft_nblen(stats.st_nlink);
	while (whitespaces <= longest_hardlink + 1)
	{
		write(1, " ", 1);
		whitespaces++;
	}
	ft_putnbr(stats.st_nlink);
}

void	print_uid(struct stat stats, size_t longest_uid)
{
	struct passwd	*p;
	size_t			whitespaces;

	write(1, " ", 1);
	if ((p = getpwuid(stats.st_uid)))
	{
		whitespaces = ft_strlen(p->pw_name);
		ft_putstr(p->pw_name);
		while (whitespaces <= longest_uid + 1)
		{
			write(1, " ", 1);
			whitespaces++;
		}
	}
	else
	{
		whitespaces = ft_nblen(stats.st_uid);
		while (whitespaces <= longest_uid + 1)
		{
			write(1, " ", 1);
			whitespaces++;
		}
		ft_putnbr(stats.st_uid);
	}
}

void	print_gid(struct stat stats, size_t longest_gid)
{
	struct group	*g;
	size_t			whitespaces;

	if ((g = getgrgid(stats.st_gid)))
	{
		whitespaces = ft_strlen(g->gr_name);
		ft_putstr(g->gr_name);
		while (whitespaces <= longest_gid + 1)
		{
			write(1, " ", 1);
			whitespaces++;
		}
	}
	else
	{
		whitespaces = ft_nblen(stats.st_gid);
		while (whitespaces <= longest_gid)
		{
			write(1, " ", 1);
			whitespaces++;
		}
		ft_putnbr(stats.st_gid);
	}
}

void	option_l_printing(t_list *list, t_longest longest, t_flags opts)
{
	t_args_node	*elem;
	int			max_ino_len;
	int			max_s_len;
	int			special;

	max_s_len = 0;
	max_ino_len = 0;
	if (opts.i == 1)
		max_ino_len = get_inode(list);
	if (opts.s == 1)
		max_s_len = get_size(list, opts);
	special = is_there_special(list);
	elem = list->head;
	while (elem)
	{
		if (opts.i == 1)
			option_i(elem, max_ino_len);
		if (opts.s == 1)
			option_s(elem, max_s_len);
		option_l_printing_controller(elem, longest, special, opts);
		write(1, "\n", 1);
		elem = elem->next;
	}
}
