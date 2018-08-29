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

#include "../../ft_ls.h"

int   is_elem_special(struct stat stats)
{
  if (S_ISDIR(stats.st_mode) == 1 || S_ISREG(stats.st_mode) == 1 ||\
    S_ISFIFO(stats.st_mode) == 1 || S_ISLNK(stats.st_mode) == 1 || S_ISSOCK(stats.st_mode) == 1)
    return (0);
  else if (S_ISCHR(stats.st_mode) == 1 || S_ISBLK(stats.st_mode) == 1)
    return (1);
  return (-1);
}

int   is_elem_symlink(struct stat stats)
{
  if (S_ISLNK(stats.st_mode) == 1)
    return (1);
  return (0);
}