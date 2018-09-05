/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:10:13 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/03 17:33:51 by aguillot         ###   ########.fr       */
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

static int	ft_str_error(char *str)
{
	int i;

	i = 0;
	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] != '/')
		i--;
	if (str[i] == '/')
		i++;
	if (i < 0)
		return (0);
	return (i);
}

void		print_errors(char *name)
{
	int		i;

	i = 0;
	ft_putstr("ft_ls: ");
	ft_putstr(name + ft_str_error(name));
	ft_putstr(": ");
	perror("");
}
