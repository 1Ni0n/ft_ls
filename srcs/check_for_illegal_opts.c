/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_illegal_opts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:04:36 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/01 11:04:38 by aguillot         ###   ########.fr       */
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
		i++;
	}
	return (1);
}

static void			set_null_opts(options *opts)
{
	if ( opts != NULL)
	{
		opts->l = 0;
		opts->a = 0;
		opts->r = 0;
		opts->R = 0;
		opts->t = 0;
	}
}

static options		*set_opts(char **av)
{
	options *opts;
	options opt;
	int		i;
	int		j;

	i = 1;
	if (!(opts = malloc(sizeof*opts)))
		return (NULL);
	set_null_opts(opts);
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

options		*check_for_illegal_opts(char **av)
{
	int		i;
	int		j;
	options	*opts;

	opts = NULL;
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--") != 0)
	{
		j = 1;
		opts = set_opts(av);
		while (av[i][j])
		{
			if (av[i][j] != 'l' && av[i][j] != 'a' && av[i][j] != 'r' &&\
					av[i][j] != 'R' && av[i][j] != 't' && av[i][j] != '1')
			{
				print_usage(av[i][j]);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (opts);
}
