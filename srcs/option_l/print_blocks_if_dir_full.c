/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir_for_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:20:28 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/02 18:18:46 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	print_blocks(char *dir_name, options opts, off_t blocks)
{
	DIR			*rep;
	dirent		*truc_lu;
	struct stat sb;
	char		*full_path;

	if ((rep = opendir(dir_name)) != NULL)
	{
		while ((truc_lu = readdir(rep)) != NULL)
		{
			full_path = check_path(dir_name, truc_lu->d_name);
			if (lstat(full_path, &sb) == 0)
			{
				if (truc_lu->d_name[0] != '.')
					blocks += sb.st_blocks;
				if (truc_lu->d_name[0] == '.' && opts.a == 1)
					blocks += sb.st_blocks;
			}
			free(full_path);
		}
	}
	if (rep)
		closedir(rep);
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putchar('\n');
}

int		is_dir_empty(S_list *list, options opts)
{
	args_node *elem;

	if (opts.a == 1)
	{
		if (list->head != NULL)
			return (0);
	}
	else if (list->head != NULL)
		return (0);
	return (1);
}

void	print_blocks_if_dir_full(S_list *list, options opts, char *dir_name)
{
	off_t blocks;

	blocks = 0;
	if (is_dir_empty(list, opts) == 0)
		print_blocks(dir_name, opts, blocks);
}
