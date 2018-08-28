/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats_for_option_l.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:18:46 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/28 09:18:48 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void  get_type(struct stat stats)
{
  if (S_ISDIR(stats.st_mode) == 1)
    write(1, "d", 1);
  else if (S_ISREG(stats.st_mode) == 1)
    write(1, "-", 1);
  else if (S_ISCHR(stats.st_mode) == 1)
    write(1, "c", 1);
  else if (S_ISBLK(stats.st_mode) == 1)
    write(1, "b", 1);
  else if (S_ISFIFO(stats.st_mode) ==1)
    write(1, "p", 1);
  else if (S_ISLNK(stats.st_mode) == 1)
    write(1, "l", 1);
  else if (S_ISSOCK(stats.st_mode) == 1)
    write(1, "s", 1);
}

void  get_permissions(struct stat stats)
{
  char permissions[10];

  permissions[0] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
  permissions[1] = (stats.st_mode & S_IWUSR) ? 'w' : '-';
  permissions[2] = (stats.st_mode & S_IXUSR) ? 'x' : '-';
  permissions[3] = (stats.st_mode & S_IRGRP) ? 'r' : '-';
  permissions[4] = (stats.st_mode & S_IWGRP) ? 'w' : '-';
  permissions[5] = (stats.st_mode & S_IXGRP) ? 'x' : '-';
  permissions[6] = (stats.st_mode & S_IROTH) ? 'r' : '-';
  permissions[7] = (stats.st_mode & S_IWOTH) ? 'w' : '-';
  permissions[8] = (stats.st_mode & S_IXOTH) ? 'x' : '-';
  permissions[9] = '\0';
  write(1, &permissions, 10);
}

void  print_full_permissions(args_node *elem)
{
  get_type(elem->stats);
  get_permissions(elem->stats);
}

void  option_l_printing_controller(args_node *elem, longest longest)
{
  if (elem)
  {
    if (elem->content)
    {
      print_full_permissions(elem);
      print_hardlinks(elem->stats, longest.hardlinks);
      print_uid(elem->stats, longest.uid);
      print_gid(elem->stats, longest.gid);
      if (is_elem_special(elem->stats) == 1)
        print_majmin(elem->stats);
      else
        print_size(elem->stats, longest.size);
      print_correct_date(elem);
      print_name(elem);
      if (is_elem_symlink(elem->stats) == 1)
        print_symlink(elem);
    }
  }
}
