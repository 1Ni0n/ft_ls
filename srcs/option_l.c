/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 09:56:02 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/27 09:56:05 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_ls.h"

int 	retreive_stats(args_node *elem)
{
	struct stat *sb;
	char	*path;

	if (elem->path == NULL)
	{
		if (lstat(elem->content, sb) == -1)
			return (0);
		else
			elem->stats = sb;
		return (1);
	}
	else
	{
		if (lstat(elem->path, sb) == -1)
			return(0);
		else
			elem->stats = sb;
		return (1);
	}
}

void	option_l(S_list *list)
{
	args_node 	*elem;

	elem = list->head;
	while (elem)
	{
		if (retreive_stats(elem) == 0)
			elem->content = NULL;
		elem = elem->next;
	}
	get_longest(list);
}