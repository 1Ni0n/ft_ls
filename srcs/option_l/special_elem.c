/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:13:11 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/02 18:13:20 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

int	is_dir_executable(char *full_path)
{
	struct stat stats;

	if (lstat(full_path, &stats) == 0)
	{
		if (S_ISDIR(stats.st_mode) && (stats.st_mode & S_IXUSR))
			return (1);
		if (!(S_ISDIR(stats.st_mode)))
			return (1);
	}
	return (0);
}

int	is_arg_executable(struct stat stats)
{
	if ((stats.st_mode & S_IXUSR))
		return (1);
	return (0);
}

int	is_dir_symlink(char *dir_name)
{
	struct stat sb;

	if (lstat(dir_name, &sb) == 0 && S_ISLNK(sb.st_mode) == 1)
		return (1);
	return (0);
}

int	is_elem_special(struct stat stats)
{
	if (S_ISDIR(stats.st_mode) == 1 || S_ISREG(stats.st_mode) == 1 ||\
	S_ISFIFO(stats.st_mode) == 1 || S_ISLNK(stats.st_mode) == 1 ||\
	S_ISSOCK(stats.st_mode) == 1)
		return (0);
	else if (S_ISCHR(stats.st_mode) == 1 || S_ISBLK(stats.st_mode) == 1)
		return (1);
	return (-1);
}

int	is_elem_symlink(struct stat stats)
{
	if (S_ISLNK(stats.st_mode) == 1)
		return (1);
	return (0);
}
