/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_correct_date.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:30:19 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/02 18:51:38 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	print_date(time_t elem_modif_time, long diff, char *correct_date)
{
	int i;

	i = 3;
	diff = 1970 + (elem_modif_time / 31557600);
	while (i++ < 10)
		write(1, &correct_date[i], 1);
	write(1, " ", 1);
	ft_putchar(diff / 1000 + '0');
	ft_putchar(((diff / 100) % 10) + '0');
	ft_putchar(((diff / 10) % 10) + '0');
	ft_putchar((diff % 10) + '0');
}

void	print_correct_date(t_args_node *elem)
{
	char	*correct_date;
	int		i;
	time_t	actual_time;
	time_t	elem_modif_time;
	long	diff;

	i = 3;
	if ((actual_time = time(NULL)) == -1)
		return ;
	correct_date = ft_strtrim(ctime(&elem->stats.st_mtime));
	elem_modif_time = elem->stats.st_mtime;
	if ((diff = elem_modif_time - actual_time) < 15768000 && diff > -15768000)
	{
		while (i++ < 15)
			write(1, &correct_date[i], 1);
	}
	else
		print_date(elem_modif_time, diff, correct_date);
	free(correct_date);
}
