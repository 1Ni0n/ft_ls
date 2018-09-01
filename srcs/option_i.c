/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:53:55 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/01 19:54:02 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int get_inode(S_list *list)
{
	args_node 	*elem;
	int 		max_len;
	int 		len;

	elem = list->head;
	max_len = 0;
	while (elem)
	{
		lstat(elem->path, &elem->stats);
		if ((len = ft_off_t_len(elem->stats.st_ino)) > max_len)
			max_len = len;
		elem = elem->next;
	}
	return	(max_len);
}

void option_i(args_node *elem, int max_len)
{
	int ino_len;

	ino_len = ft_off_t_len(elem->stats.st_ino);
	while (max_len > ino_len++)
		write(1, " ", 1);
	ft_putoff_t(elem->stats.st_ino);
	write(1, " ", 1);
}
