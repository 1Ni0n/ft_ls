/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir_for_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:20:28 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/28 17:20:30 by aguillot         ###   ########.fr       */
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

int	check_dir_for_l(char *dir_name)
{
	struct stat sb;
	DIR			*rep;
	dirent		*truc_lu;
	int 		count;

	count = 0;
	if ((rep = opendir(dir_name)) != NULL)
	{
		while ((truc_lu = readdir(rep)) != NULL)
		{
			if (count > 1)
				return (1);
			count++;
		}
	}
	return (0);
}