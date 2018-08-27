#include "../ft_ls.h"

int   is_elem_special(struct stat stats)
{
  if (S_ISDIR(stats.st_mode) == 1 || S_ISREG(stats.st_mode) == 1 ||\
    S_ISFIFO(stats.st_mode) ==1 || S_ISLNK(stats.st_mode) == 1\
    S_ISSOCK(stats.st_mode) == 1)
    return (0);
  else if (S_ISCHR(stats.st_mode) == 1 || S_ISBLK(stats.st_mode) == 1)
    return (1);
}

void  get_longest_mami(args_node *elem, longest *longest)
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
      if (ft_nblen(major) > longest->major)
        longest->major = ft_nblen(major);
      if (ft_nblen(minor) >longest->minor)
        longest->minor = ft_nblen(minor);
      mami = ft_nblen(major) + ft_nblen(minor);
      if (mami > longest->mami)
        longest->mami = mami + 2;
      if (longest->size > longest->mami)
        longest->size_mami = longest->size;
      else if (longest->size < longest->mami)
        longest->size_mami = longest->mami;
    }
  }
}
