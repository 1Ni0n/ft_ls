/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_mami.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:48:50 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/28 09:48:53 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int look_for_special_elem(S_list *list)
{
  args_node *elem;
  struct stat stats;

  elem = list->head;
  while (elem)
  {
    stats = elem->stats;
    if (S_ISCHR(stats.st_mode) == 1 || S_ISBLK(stats.st_mode) == 1)
      return (1);
    elem = elem->next;
  }
  return (0);
}

int   is_elem_special(struct stat stats)
{
  if (S_ISDIR(stats.st_mode) == 1 || S_ISREG(stats.st_mode) == 1 ||\
    S_ISFIFO(stats.st_mode) == 1 || S_ISLNK(stats.st_mode) == 1 || S_ISSOCK(stats.st_mode) == 1)
    return (0);
  else if (S_ISCHR(stats.st_mode) == 1 || S_ISBLK(stats.st_mode) == 1)
    return (1);
  return (-1);
}

void  get_longest_majmin(args_node *elem, longest *longest)
{
  size_t major;
  size_t minor;
  size_t mami;

  mami = 0;
  if (elem->content)
  {
    if (is_elem_special(elem->stats) == 0)
      return;
    else
    {
      major = major(elem->stats.st_rdev);
      minor = minor(elem->stats.st_rdev);
      if (ft_nblen(major) > longest->majmin)
        longest->majmin = ft_nblen(major);
      if (ft_nblen(minor) >longest->majmin)
        longest->majmin = ft_nblen(minor);
    }
  }
}
