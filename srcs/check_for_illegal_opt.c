/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_illegal_opt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:30:25 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/28 11:30:28 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int				check_if_only_opts(char **av)
{
	int	i;

	i = 1;
	while (av[i] && ft_strcmp(av[i], "--") != 0)
	{
		if (av[i][0] != '-')
			return (0);
		i++;
	}
	while (av[i])
	{
		if (av[i + 1] != NULL)
			return (0);
	}
	return (1);
}

static void		print_usage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-Ralrt1] [file ...]");
	ft_putchar('\n');
}

void 		set_null_opts(options **opts)
{
	if ((*opts) != NULL)
	{
		(*opts)->l = 0;
		(*opts)->a = 0;
		(*opts)->r = 0;
		(*opts)->R = 0;
		(*opts)->t = 0;
		(*opts)->one = 0;
	}
}

options		*set_opts(int ac, char **av)
{
	options *opts;
	int 	i;
	int 	j;

	i = 1;
	if (!(opts = malloc(sizeof *opts)))
		return (NULL);
	set_null_opts(&opts);
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[1], "--") != 0)
	{
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] == 'l')
				opts->l = 1;
			if (av[i][j] == 'a')
				opts->a = 1;
			if (av[i][j] == 'r')
				opts->r = 1;
			if (av[i][j] == 'R')
				opts->R = 1;
			if (av[i][j] == 't')
				opts->t = 1;
			if (av[i][j] == '1')
				opts->one = 1;
			j++;
		}
		i++;
	}
	return (opts);
}

options		*check_for_illegal_opt(int ac, char **av)
{
	int 	i;
	int 	j;
	options	*opts;

	opts = NULL;
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--") != 0)
	{
		j = 1;
		opts = set_opts(ac, av);
		while (av[i][j])
		{
			if (av[i][j] != 'l' && av[i][j] != 'a' && av[i][j] != 'r' && av[i][j] != 'R' && av[i][j] != 't' && av[i][j] != '1')
			{
				print_usage(av[i][j]);
				exit(1);
			}
			j++;
		}
		i++;
	}
	//printf("l: %d, a: %d, r: %d, R: %d, t: %d, one: %d\n", opts->l, opts->a, opts->r, opts->R, opts->t, opts->one);
	return (opts);
}
