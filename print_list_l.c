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

void	print_blocks(char *dir_name, options *opts)
{
	DIR			*rep;
	dirent		*truc_lu;
	struct stat sb;
	long 		blocks;
	char 		*full_path;

	blocks = 0;
	if ((rep = opendir(dir_name)) != NULL)
	{
		while ((truc_lu = readdir(rep)) != NULL)
		{
			full_path = check_path(dir_name, truc_lu->d_name);
			if (lstat(full_path, &sb) == 0)
			{
				if (truc_lu->d_name[0] != '.')
					blocks += sb.st_blocks;
				if (truc_lu->d_name[0] == '.' && opts != NULL && opts->a == 1)
					blocks += sb.st_blocks;
			}
		}
	}
	closedir(rep);
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putchar('\n');
}

void 	print_list_l(S_list *list, longest *longest)
{
	args_node 	*elem;
	size_t		max;
	size_t 		size;

	if ((elem = list->head))
	{
		while (elem)
		{
			if (elem->content != NULL)
			{
				ft_putstr(elem->perm);
				ft_putchar(' ');
				max = longest->hardlinks;				
				size  = ft_nblen(elem->hardlinks);
				while (max >= size)
				{
					ft_putchar(32);
					max--;
				}
				ft_putnbr(elem->hardlinks);
				ft_putchar(' ');
				//printf("BOOBS\n");
				max = longest->uid;
				if (elem->uid)
					size = ft_strlen(elem->uid);
				else
					size = ft_nblen(elem->uidd);
				while (max > size)
				{
					ft_putchar(32);
					max--;
				}
				if (elem->uid)
					ft_putstr(elem->uid);
				else
					ft_putnbr(elem->uidd);
				ft_putstr("  ");
				max = longest->gid;
				if (elem->gid)
					size = ft_strlen(elem->gid);
				else
					size = ft_nblen(elem->gidd);
				while (max > size)
				{
					ft_putchar(32);
					max--;
				}
				if (elem->gid)
					ft_putstr(elem->gid);
				else
					ft_putnbr(elem->gidd);
				ft_putchar(32);
				max = longest->size;
				size = ft_nblen(elem->size);
				while (max > size)
				{
					ft_putchar(32);
					max--;
				}
				if (elem->perm[0] != 'b' && elem->perm[0] != 'c')
					ft_putnbr(elem->size);
				else
				{
					ft_putstr("   ");
					ft_putnbr(elem->major);
					ft_putstr(",   ");
					ft_putnbr(elem->minor);
				}
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
			}
			elem = elem->next;
		}
	}
}