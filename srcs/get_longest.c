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

void	get_longest_hardlink(args_node *elem, longest *longest)
{
	size_t hardlinks;
	size_t len;

	hardlinks = 0;
	if (elem->content)
	{
		hardlinks = elem->stats.st_nlink;
		if ((len = ft_nblen(hardlinks)) > longest->hardlinks)
			longest->hardlinks = len;
	}
}

void	get_longest_uid(args_node *elem, longest *longest)
{
	size_t          uid_len;
  size_t          uid;
  struct passwd   *p;

  uid_len = 0;
	if (elem->content)
	{
		if ((p = getpwuid(elem->stats.st_uid)) != NULL)
    {
      if ((uid_len = ft_strlen(p->pw_name)) > longest->uid)
        longest->uid = uid_len;
    }
		else
		{
      uid = elem->stats.st_uid;
      if ((uid_len = ft_nblen(uid)) > longest->uid)
        longest->uid = uid_len;
    }
	}
}

void  get_longest_gid(args_node *elem, longest *longest)
{
  size_t          gid_len;
  size_t          gid;
  struct group   *g;

  gid_len = 0;
  if (elem->content)
  {
    if ((g = getgrgid(elem->stats.st_gid)) != NULL)
    {
      if ((gid_len = ft_strlen(g->gr_name)) > longest->gid)
        longest->gid = gid_len;
    }
    else
    {
      gid = elem->stats.st_gid;
      if ((gid_len = ft_nblen(gid)) > longest->gid)
        longest->gid = gid_len;
    }
  }
}

void  get_longest_size(args_node *elem, longest *longest)
{
  long size;

  if (elem->content)
  {
    if ((size = ft_nblen(elem->stats.st_size)) > longest->size)
      longest->size = size;
  }
}

longest	 get_longest(S_list *list)
{
	args_node 	*elem;
	longest 	longest;

	elem = list->head;
	longest.hardlinks = 1;
	longest.uid = 1;
	longest.gid = 1;
	longest.size = 1;
	while (elem)
	{
		get_longest_hardlink(elem, &longest);
		get_longest_uid(elem, &longest);
		get_longest_gid(elem, &longest);
		get_longest_size(elem, &longest);
		elem = elem->next;
	} 
  return(longest);
}
