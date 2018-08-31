/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:23:28 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/31 12:23:30 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	args_controller(int ac, char **av)
{
	options	opts;

	if (av[1][0] == '-')
	{
		opts = check_for_illegal_opt(ac, av);
		ls_controller(av, opts);
	}
	else
		ls_controller(av, opts);
}
