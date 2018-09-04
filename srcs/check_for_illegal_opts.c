/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_illegal_opts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:04:36 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/04 11:45:35 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int					check_if_only_opts(char **av)
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

static void			set_null_opts(t_flags *opts)
{
	if (opts != NULL)
	{
		opts->l = 0;
		opts->a = 0;
		opts->r = 0;
		opts->rr = 0;
		opts->t = 0;
	}
}

void				set_em(char **av, t_flags **opts, int i, int j)
{
	if (av[i][j] == 'A')
		(*opts)->aa = 1;
	if (av[i][j] == 'i')
		(*opts)->i = 1;
	if (av[i][j] == 'F')
		(*opts)->ff = 1;
	if (av[i][j] == 's')
		(*opts)->s = 1;
	if (av[i][j] == 'c')
		(*opts)->c = 1;
	if (av[i][j] == 'l')
		(*opts)->l = 1;
	if (av[i][j] == 'a')
		(*opts)->a = 1;
	if (av[i][j] == 'r')
		(*opts)->r = 1;
	if (av[i][j] == 'R')
		(*opts)->rr = 1;
	if (av[i][j] == 't')
		(*opts)->t = 1;
	if (av[i][j] == '1')
		(*opts)->one = 1;
}

static t_flags		*set_opts(char **av)
{
	t_flags *opts;
	int		i;
	int		j;

	i = 1;
	if (!(opts = malloc(sizeof(*opts))))
		return (NULL);
	set_null_opts(opts);
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[1], "--") != 0)
	{
		j = 1;
		while (av[i][j])
		{
			set_em(av, &opts, i, j);
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

t_flags				*check_for_illegal_opts(char **av)
{
	int		i;
	int		j;
	t_flags	*opts;

	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--") != 0)
	{
		j = 1;
		opts = set_opts(av);
		while (av[i][j])
		{
			if (av[i][j] != 'l' && av[i][j] != 'a' && av[i][j] != 'r' &&\
					av[i][j] != 'R' && av[i][j] != 't' && av[i][j] != '1'\
					&& av[i][j] != 'A' && av[i][j] != 'i' && av[i][j] != 'F'\
					&& av[i][j] != 's' && av[i][j] != 'c')
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
