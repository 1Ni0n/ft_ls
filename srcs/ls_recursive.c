/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:13:15 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/04 11:46:02 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		ls_recursive(t_list *list, t_flags opts)
{
	t_args_node	*arg;
	struct stat sb;

	arg = list->head;
	while (arg)
	{
		if (check_if_curr_or_prev_dir(arg->content) == 0)
		{
			if (lstat(arg->path, &sb) == 0 && !S_ISLNK(sb.st_mode)\
					&& S_ISDIR(sb.st_mode))
			{
				ft_putchar('\n');
				ft_putstr(arg->path);
				ft_putstr(":\n");
				main_ls(arg->path, opts);
			}
		}
		arg = arg->next;
	}
	free_list(list);
}
