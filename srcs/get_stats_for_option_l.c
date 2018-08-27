#include "../ft_ls.h"

int  get_type(struct stat stats)
{
  if (S_ISDIR(stats.st_mode) == 1)
    write(1, "d", 1);
  else if (S_ISREG(stats.st_mode) == 1)
    write(1, "-", 1);
  else if (S_ISCHR(stats.st_mode) == 1)
  {
    write(1, "c", 1);
    return (1);
  }
  else if (S_ISBLK(stats.st_mode) == 1)
  {
    write(1, "b", 1);
    return (1);
  }
  else if (S_ISFIFO(stats.st_mode) ==1)
    write(1, "p", 1);
  else if (S_ISLNK(stats.st_mode) == 1)
    write(1, "l", 1);
  else if (S_ISSOCK(stats.st_mode) == 1)
    write(1, "s", 1);
  return (0);
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

int  get_full_permissions(args_node *elem)
{
  int special;

  special = get_type(elem->stats);
  get_permissions(elem->stats);
  return (special);
}

void  get_stats_for_option_l(args_node *elem, longest longest)
{
  int special;

  if (elem)
  {
    if (elem->content)
    {
      special = get_permissions(elem->stats);
      print_hardlinks(elem->stats, longest.hardlinks);
      print_uid(elem->stats, longest.uid);
      print_gid(elem->stats, longest.gid);
      if (special == 0)
        print_size(elem->stats, longest.size);
      if (special == 1)
      {
        if (is_elem_special(elem->stats) == 1)
          print_mami(elem->stats, longest);
        else
          print_size(elem->stats, longest);
      }
    }
  }
}
