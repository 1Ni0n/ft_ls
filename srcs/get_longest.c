/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:50:11 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/27 10:50:12 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	get_longest_hardlinks(args_node *elem, longest *longest)
{
	size_t hardlinks;
	size_t len;

	hardlinks = 0;
	if (elem->stats != NULL)
	{
		hardlinks = elem->stats->st_nlink;
		if ((len = ft_nblen(hardlinks)) > longest->hardlinks)
			longest->hardlinks = len;
	}
}

void	get_longest_uid(args_node *elem, longest *longest)
{
	size_t uid_len;

	if (elem->stats != NULL)
	{
		if ((p = getpwuid(sb.st_uid)) != NULL)
			elem->uid = ft_strdup(p->pw_name);
		else
			elem->uidd = sb.st_uid;
	}
}

void	get_longest(S_list *list)
{
	args_node 	*elem;
	longest 	longest;

	elem = list->head;
	longest.hardlinks = 0;
	longest.uid = 0;
	longest.gid = 0;
	longest.size = 0;
	while (elem)
	{
		get_longest_hardlinks(elem, &longest);
		get_longest_uid(elem, &longest);
		get_longest_gid(elem, &longest);
		get_longest_size(elem, &longest);
		elem = elem->next;
	}
}
