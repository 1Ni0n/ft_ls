/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:31:49 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/03 17:33:15 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int				check_inexistant(char **av)
{
	t_list		*does_not_exist_list;
	int			i;
	struct stat	sb;

	does_not_exist_list = new_s_list();
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--") != 0)
		i++;
	if (ft_strcmp(av[i], "--") == 0)
		i++;
	while (av[i])
	{
		if (lstat(av[i], &sb) == -1 && (errno & ENOENT) == 2)
			append_to_list(does_not_exist_list, av[i], NULL);
		i++;
	}
	if (does_not_exist_list->head == NULL)
	{
		free_list(does_not_exist_list);
		return (0);
	}
	merge_sort(&(does_not_exist_list->head), *(set_useless_opts()));
	print_does_not_exist_list(does_not_exist_list);
	free_list(does_not_exist_list);
	return (1);
}

int				check_files(char **av, t_flags opts)
{
	t_list		*no_dir_list;
	struct stat	sb;
	int			i;

	no_dir_list = new_s_list();
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--") != 0)
		i++;
	while (av[i])
	{
		if (lstat(av[i], &sb) == 0 && (S_ISDIR(sb.st_mode)) == 0)
		{
			if (!S_ISLNK(sb.st_mode))
				append_to_list(no_dir_list, av[i], NULL);
			else if (opts.l == 1)
				append_to_list(no_dir_list, av[i], NULL);
		}
		i++;
	}
	return (check_files_end(no_dir_list, opts));
}

t_list			*check_dir(char **av, t_flags opts)
{
	t_list		*dir_list;
	struct stat sb;
	int			i;

	dir_list = new_s_list();
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i], "--") != 0)
		i++;
	while (av[i])
	{
		if (lstat(av[i], &sb) == 0)
		{
			if (S_ISDIR(sb.st_mode) == 1)
				append_to_list(dir_list, av[i], NULL);
			else if (S_ISLNK(sb.st_mode) == 1 && opts.l == 0)
				append_to_list(dir_list, av[i], NULL);
		}
		i++;
	}
	merge_sort(&(dir_list->head), opts);
	return (dir_list);
}

void			manage_dir(t_list *dir_list, int inexistant, int files,\
		t_flags opts)
{
	t_args_node *dir;

	dir = dir_list->head;
	while (dir)
	{
		if (dir_list->length > 1 || inexistant == 1 || files == 1)
		{
			ft_putstr(dir->content);
			ft_putstr(":\n");
		}
		main_ls(dir->content, opts);
		if (dir->next != NULL || (files == 1 && dir->next != NULL))
			ft_putchar('\n');
		dir = dir->next;
	}
}

void			ls_controller(char **av, t_flags opts)
{
	t_list		*dir_list;
	int			inexistant;
	int			files;
	char		*ptr;

	if (check_if_only_opts(av) == 1)
	{
		main_ls((ptr = ft_strdup("./")), opts);
		free(ptr);
		return ;
	}
	inexistant = check_inexistant(av);
	files = check_files(av, opts);
	dir_list = check_dir(av, opts);
	if (files == 1 && dir_list->length >= 1)
		ft_putchar('\n');
	if (dir_list->head != NULL)
		manage_dir(dir_list, inexistant, files, opts);
	free_list(dir_list);
}
