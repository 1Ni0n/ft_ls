/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:13:15 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/28 15:13:17 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ls_recursive(S_list *list, options *opts)
{
	args_node	*arg;
	struct stat sb;
	int			print_newline;

	arg = list->head;
	print_newline = 0;
	while (arg)
	{
		//printf("PATH: %s, STAT:%d, DIR?: %d\n", arg->path, stat(arg->path, &sb), S_ISDIR(sb.st_mode));
		if (stat(arg->path, &sb) == 0 && S_ISDIR(sb.st_mode) == 1)
			if (lstat(arg->path, &sb) == 0 && S_ISLNK(sb.st_mode) != 1)
			{
				print_newline = 1;
				ft_putstr(arg->path);
			 	ft_putstr(":\n");
				main_ls(arg->path, opts, print_newline);
			}
			arg = arg->next;
	}
}
