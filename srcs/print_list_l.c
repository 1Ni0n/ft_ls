/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:25:14 by aguillot          #+#    #+#             */
/*   Updated: 2018/06/18 16:25:25 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

long 	get_total_block_nb(args_node *elem)
{
	long 	total_block_nb;

	total_block_nb = 0;
	while (elem)
	{
		total_block_nb += elem->nb_of_blocks;
		elem = elem->next;
	}
	return (total_block_nb);
}

void 	print_list_l(S_list *list, longest *longest)
{
	args_node 	*elem;
	size_t		max;
	size_t 		size;

	elem = list->head;
	if (elem != NULL)
	{
		ft_putstr("total ");
		ft_putnbr(get_total_block_nb(elem));
		ft_putchar('\n');
	}
	while (elem)
	{
		ft_putstr(elem->perm);
		ft_putchar(' ');
		max = longest->hardlinks;
		size  = ft_nblen(elem->hardlinks);
		while (max > size)
		{
			ft_putchar(32);
			max--;
		}
		ft_putnbr(elem->hardlinks);
		ft_putchar(' ');
		max = longest->uid;
		size = ft_strlen(elem->uid);
		while (max > size)
		{
			ft_putchar(32);
			max--;
		}
		ft_putstr(elem->uid);
		ft_putstr("  ");
		max = longest->gid;
		size = ft_strlen(elem->gid);
		while (max > size)
		{
			ft_putchar(32);
			max--;
		}
		ft_putstr(elem->gid);
		ft_putchar(32);
		max = longest->size;
		size = ft_nblen(elem->size);
		while (max > size)
		{
			ft_putchar(32);
			max--;
		}
		ft_putnbr(elem->size);
		ft_putchar(32);
		ft_putstr(elem->mtimefull);
		ft_putchar(32);
		ft_putstr(elem->content);
		if (elem->symlink != NULL)
		{
			ft_putstr(" -> ");
			ft_putstr(elem->symlink);
		}
		ft_putchar('\n');
		elem = elem->next;
	}
}