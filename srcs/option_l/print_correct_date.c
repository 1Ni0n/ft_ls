/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_correct_date.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:30:19 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/28 15:30:20 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	print_correct_date(args_node *elem)
{
	char 	*correct_date;
	int 	i;
	time_t 	actual_time;
	time_t  elem_modification_time;
	long	diff;

	i = 3;
	if ((actual_time = time(NULL)) == -1)
		return;
	correct_date = ft_strtrim(ctime(&elem->stats.st_mtime));
	elem_modification_time = elem->stats.st_mtime;
	if ((diff = elem_modification_time - actual_time) < 15768000 && diff > -15768000)
	{
		while (i++ < 15)
			write(1, &correct_date[i], 1);
	}
	//printf("DIFF: %ld\n", diff);
	//if (diff >= 15768000 || diff <= -15768000)
	else
	{
		diff = 1970 + (elem->mtime / 31557600);
		while (i++ < 10)
			write(1, &correct_date[i], 1);
		write(1, " ", 1);
		ft_putchar(diff / 1000 + '0');
		ft_putchar(((diff / 100) % 10) + '0');
		ft_putchar(((diff / 10) % 10) + '0');
		ft_putchar((diff % 10) + '0');
	}
	free(correct_date);
}