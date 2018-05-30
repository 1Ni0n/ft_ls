/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:36:24 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/04 16:24:30 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int	main(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && ft_strcmp(av[1], "--") == 0) || (ac == 2 && ft_strcmp(av[1], ".") == 0))
		simplest_ls();
	else if (ac > 1)
		args_controller(ac, av);
	return (0);
}