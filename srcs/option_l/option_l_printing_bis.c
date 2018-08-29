/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l_printing_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:19:30 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/28 09:19:31 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void  print_size(struct stat stats, size_t longest_size)
{
  size_t whitespaces;

  whitespaces = ft_nblen(stats.st_size);
  while (whitespaces < longest_size)
  {
    write(1, " ", 1);
    whitespaces++;
  }
  ft_putoff_t(stats.st_size);
  write(1, " ", 1);
}

void print_majmin(struct stat stats)
{
	int 	majmin;
	size_t 	whitespaces;

	majmin = major(stats.st_rdev);
	whitespaces = ft_nblen(majmin);
	while (whitespaces < 3)
	{
		write(1, " ", 1);
		whitespaces++;
	}
	ft_putnbr(majmin);
	write(1, ", ", 2);
	majmin = minor(stats.st_rdev);
	whitespaces = ft_nblen(majmin);
	while (whitespaces < 3)
	{
    	write(1, " ", 1);
    	whitespaces++;
	}
	ft_putnbr(majmin); 
	write(1, " ", 1);
}

void 	print_name(args_node *elem)
{
	write(1, " ", 1);
	ft_putstr(elem->content);
}

void 	print_symlink(args_node *elem)
{
	int 	link;
	char	symlink[255];
	char	*path;

	if (elem->path == NULL)
		path = ft_strdup(elem->content);
	else
		path = ft_strdup(elem->path);
	if ((link = readlink(path, symlink, 255)) != -1)
	{
		symlink[link] = '\0';
		write(1, " -> ", 4);
		write(1, &symlink, link);		
	}
}
