/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 09:15:45 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/03 13:18:30 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		check_for_opt_a(t_flags opts)
{
	if (opts.a == 0)
		return (0);
	return (1);
}

int		check_if_curr_or_prev_dir(char *name)
{
	if (!name)
		return (0);
	if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0)
		return (0);
	return (1);
}
