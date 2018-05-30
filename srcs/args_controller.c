/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:09:49 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/16 14:09:51 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	args_controller(int ac, char **av)
{
	options	*opts;

	opts = NULL;
	if (av[1][0] == '-')
	{
		opts = check_for_illegal_opt(ac, av);
		ls_controller(av, opts);
	}
	else
		printf("args_no_opt\n");
		//ls_arg_no_opt(ac, av);
}