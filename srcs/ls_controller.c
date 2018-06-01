/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:31:49 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/28 13:31:51 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	check_inexistant(char **av)
{
	S_list	*does_not_exist_list;
	int 	i;
	struct stat sb;

	does_not_exist_list = new_s_list();
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--"))
		i++;
	while (av[i])
	{
		if (stat(av[i], &sb) == -1 && (errno & ENOENT) == 2)
			append_to_list(does_not_exist_list, av[i], 0, NULL);
		i++;
	}
	sort_list(&does_not_exist_list);
	print_does_not_exist_list(does_not_exist_list);
}

void	check_files(char **av, options *opts)
{
	S_list 		*no_dir_list;
	struct stat sb;
	int 		i;

	no_dir_list = new_s_list();
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--") != 0)
		i++;
	while (av[i])
	{
		if (stat(av[i], &sb) == 0 && (S_ISDIR(sb.st_mode)) == 0)
			append_to_list(no_dir_list, av[i], sb.st_mtime, NULL);
		i++;
	}
	sort_list(&no_dir_list);
	if (opts != NULL && opts->t == 1)
		sort_list_t(&no_dir_list);
	if (opts != NULL && opts->r == 1)
		sort_list_r(&no_dir_list);
	print_list(no_dir_list);
}

S_list 	*check_dir(char **av, options *opts)
{
	S_list 		*dir_list;
	struct stat sb;
	int 		i;

	dir_list = new_s_list();
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--") != 0)
		i++;
	while (av[i])
	{
		printf("AV: %s, STAT: %d, DIR?: %d\n", av[i], stat(av[i], &sb), S_ISDIR(sb.st_mode));
		if (stat(av[i], &sb) == 0 && (S_ISDIR(sb.st_mode)) == 1)
		{
			//if (av[i][0] == '.' && opts->a == 1)
				append_to_list(dir_list, av[i], sb.st_mtime, NULL);
			//else if (av[i][0] != '.')
			//	append_to_list(dir_list, av[i], sb.st_mtime, NULL);
		}
		i++;
	}
	sort_list(&dir_list);
	if (opts != NULL && opts->t == 1)
		sort_list_t(&dir_list);
	if (opts != NULL && opts->r == 1)
		sort_list_r(&dir_list);
	//print_list(dir_list);
	return (dir_list);
}

//On est toujours que au niveau des arguments dans 
void	ls_controller(char **av, options *opts)
{
	//on instancie la dir_list que va nous renvoyer check_dir, pour ensuite la passer à main_ls;
	S_list 		*dir_list;
	args_node 	*dir;

	if (check_if_only_opts(av) == 1)
		main_ls("./", opts);
	check_inexistant(av);
	check_files(av, opts);
	dir_list = check_dir(av, opts);
	if (dir_list->head != NULL)
	{
		dir = dir_list->head;
		while (dir)
		{
			main_ls(dir->content, opts);
			dir = dir->next;
		}
	}
}