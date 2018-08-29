/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:10:13 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/29 14:10:18 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		print_usage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-Ralrt1] [file ...]");
	ft_putchar('\n');
}

void 	print_errors(char *name)
{
	char *simple_name;
	int i;
	char *ptr;

	i = 0;
	ft_putstr("ft_ls: ");
	while (name[i])
	{
		if (name[i] == '/')
		{
			ft_putstr(name + i + 1);
		}
		i++;
	}
	if (ft_strrchr(name, '/') == 0)
		ft_putstr(name);		
	ft_putstr(": ");
	perror("");		

}