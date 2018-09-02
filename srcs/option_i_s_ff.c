/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_i_s_ff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:19:40 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/02 18:58:25 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	option_ff(args_node *elem)
{
	mode_t mode;

	lstat(elem->path, &elem->stats);
	mode = elem->stats.st_mode;
	if (S_ISREG(mode) && (mode & S_IXUSR))
		write(1, "*", 1);
	else if (S_ISDIR(mode))
		write(1, "/", 1);
	else if (S_ISLNK(mode))
		write(1, "@", 1);
	else if (S_ISFIFO(mode))
		write(1, "|", 1);
}

int		get_size(S_list *list, options opts)
{
	args_node	*elem;
	int			max_len;
	int			len;
	int			blocks;

	max_len = 0;
	len = 0;
	blocks = 0;
	elem = list->head;
	while (elem)
	{
		lstat(elem->path, &elem->stats);
		if ((len = ft_off_t_len(elem->stats.st_blocks)) > max_len)
			max_len = len;
		blocks += elem->stats.st_blocks;
		elem = elem->next;
	}
	if (opts.l == 0)
	{
		ft_putstr("total: ");
		ft_putoff_t(blocks);
		write(1, "\n", 1);
	}
	return (max_len);
}

void	option_s(args_node *elem, int max_len)
{
	int size_len;

	if ((size_len = ft_off_t_len(elem->stats.st_blocks)) == 0)
		size_len = 1;
	while (max_len > size_len++)
		write(1, " ", 1);
	ft_putoff_t(elem->stats.st_blocks);
	write(1, " ", 1);
}

int		get_inode(S_list *list)
{
	args_node	*elem;
	int			max_len;
	int			len;

	elem = list->head;
	max_len = 0;
	while (elem)
	{
		lstat(elem->path, &elem->stats);
		if ((len = ft_off_t_len(elem->stats.st_ino)) > max_len)
			max_len = len;
		elem = elem->next;
	}
	return (max_len);
}

void	option_i(args_node *elem, int max_len)
{
	int ino_len;

	ino_len = ft_off_t_len(elem->stats.st_ino);
	while (max_len > ino_len++)
		write(1, " ", 1);
	ft_putoff_t(elem->stats.st_ino);
	write(1, " ", 1);
}
