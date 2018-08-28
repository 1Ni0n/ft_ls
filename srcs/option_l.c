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
	struct stat sb;
	char	*path;

  if (elem->path == NULL)
	{
		if (lstat(elem->content, &sb) == -1)
			return (0);
		else
			elem->stats = sb;
		return (1);
	}
	else
	{
		if (lstat(elem->path, &sb) == -1)
			return(0);
		else
			elem->stats = sb;
    return (1);
	}
}

void	option_l(S_list *list)
{
	args_node 	*elem;
  	longest     longest;

	elem = list->head;
	while (elem)
	{
		if (retreive_stats(elem) == 0)
			elem->content = NULL; //cest comme ca quon protege les fonctions suivantes de taper dans struct stats si lstat na pas marche.
		elem = elem->next;
	}
	longest = get_longest(list);
  option_l_printing(list, longest);
  //printf("hardlinks: %lu uid: %lu, gid: %lu, size: %lu\n", longest.hardlinks, longest.uid, longest.gid, longest.size);
}
