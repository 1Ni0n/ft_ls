/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l_printing_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:19:30 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/28 09:19:31 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void  print_size(struct stat stats, longest longest, int special_elem)
{
  size_t whitespaces;
  size_t biggest;

  whitespaces = ft_nblen(stats.st_size);
  if ((special_elem == 1 && longest.size > longest.majmin * 2 + 3) || special_elem == 0)
  	biggest = longest.size;
  else if (special_elem == 1 && longest.size < longest.majmin * 2 + 3)
  	biggest = longest.majmin + 3;
  while (whitespaces <= biggest)
  {
    write(1, " ", 1);
    whitespaces++;
  }
  ft_putnbr(stats.st_size);
}

void print_majmin(struct stat stats, longest longest)
{
	size_t 	whitespaces;
	size_t 	biggest;
	int 	majmin;

	majmin = major(stats.st_rdev);
	whitespaces = ft_nblen(majmin);
	if (longest.size > longest.majmin)
  		biggest = longest.size;
  	else
  		biggest = longest.majmin;
	while (whitespaces <= biggest)
	{
	    write(1, " ", 1);
	    whitespaces++;
	}
	ft_putnbr(majmin);
	write(1, ",", 1);
	majmin = minor(stats.st_rdev);
	whitespaces = ft_nblen(majmin);
	while (whitespaces <= longest.majmin)
	{
    	write(1, " ", 1);
    	whitespaces++;
	}
	ft_putnbr(majmin);
}