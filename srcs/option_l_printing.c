#include "../ft_ls.h"

void  print_hardlinks(struct stat stats, size_t longest_hardlink)
{
  size_t whitespaces;

  whitespaces = ft_nblen(stats.st_nlink);
  while (whitespaces <= longest_hardlink)
  {
    write(1, " ", 1);
    whitespaces++;
  }
  ft_putnbr(stats.st_nlink);
}

void  print_uid(struct stat stats, size_t longest_uid)
{
  struct passwd *p;
  size_t whitespaces;

  if ((p = getpwuid(stats.st_uid)))
  {
    whitespaces = ft_strlen(p->pw_name);
    while (whitespaces <= longest_uid)
    {
      write(1, " ", 1);
      whitespaces++;
    }
    ft_putstr(p->pw_name);
  }
  else
  {
    whitespaces = ft_nblen(stats.st_uid);
    while (whitespaces <= longest_uid)
    {
      write(1, " ", 1);
      whitespaces++;
    }
    ft_putnbr(stats.st_uid);
  }
}

void  print_gid(struct stat stats, size_t longest_gid)
{
  struct group *g;
  size_t whitespaces;

  if ((g = getgrgid(stats.st_gid)))
  {
    whitespaces = ft_strlen(g->gr_name);
    while (whitespaces <= longest_gid)
    {
      write(1, " ", 1);
      whitespaces++;
    }
    ft_putstr(g->gr_name);
  }
  else
  {
    whitespaces = ft_nblen(stats.st_gid);
    while (whitespaces <= longest_gid)
    {
      write(1, " ", 1);
      whitespaces++;
    }
    ft_putnbr(stats.st_gid);
  }
}

void  print_size(struct stat stats, size_t longest_size)
{
  size_t whitespaces;

  whitespaces = ft_nblen(stats.st_size);
  while (whitespaces <= longest_size)
  {
    write(1, " ", 1);
    whitespaces++;
  }
  ft_putnbr(stats.st_size);
}

void  option_l_printing(S_list *list, longest longest)
{
  args_node *elem;

  elem = list->head;
  while (elem)
  {
    get_stats_for_option_l(elem, longest);
    write(1, "\n", 1);
    elem = elem->next;
  }
}
