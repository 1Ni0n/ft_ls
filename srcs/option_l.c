/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:13:32 by aguillot          #+#    #+#             */
/*   Updated: 2018/06/14 15:13:34 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	get_perm(args_node *elem)
{
	char		*path;
	struct stat sb;
	struct stat sb2;

	if (elem->path == NULL)
			path = ft_strdup(elem->content);
		else
			path = ft_strdup(elem->path);
	if (stat(path, &sb) == -1 || lstat(path, &sb2) == -1)
		return;
	if (S_ISLNK(sb2.st_mode) == 1)
	{
		elem->perm[0] = 'l';
		sb = sb2;
	}
	if (S_ISDIR(sb.st_mode) == 1)
		elem->perm[0] = 'd';
	else if (S_ISREG(sb.st_mode) == 1)
		elem->perm[0] = '-';
	else if (S_ISCHR(sb.st_mode) == 1)
		elem->perm[0] = 'c';
	else if (S_ISBLK(sb.st_mode) == 1)
		elem->perm[0] = 'b';
	else if (S_ISFIFO(sb.st_mode) ==1)
		elem->perm[0] = 'p';
	else if (S_ISLNK(sb.st_mode) == 1)
		elem->perm[0] = 'l';
	else if (S_ISSOCK(sb.st_mode) == 1)
		elem->perm[0] = 's';
	elem->perm[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
	elem->perm[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
	elem->perm[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
	elem->perm[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
	elem->perm[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
	elem->perm[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
	elem->perm[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
	elem->perm[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
	elem->perm[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
	free(path);
}

void get_infos(args_node *elem)
{
	char		*path;
	struct stat sb;
	struct stat sb2;
	
	if (elem->path == NULL)
			path = ft_strdup(elem->content);
		else
			path = ft_strdup(elem->path);
	if (stat(path, &sb) == -1 || lstat(path, &sb2) == -1)
		return;
	if (S_ISLNK(sb2.st_mode) == 1)
		sb = sb2;
	elem->uid = getpwuid(sb.st_uid);
	elem->gid = getgrgid(sb.st_gid);
	get_perm(elem);	
	free(path);
}


void	option_l(S_list *list)
{
	args_node *elem;

	elem = list->head;
	while (elem)
	{		
		get_infos(elem);
		printf("ELEM:%s, UID: %s, GID: %s, PERM:%s\n", elem->content, elem->uid, elem->gid, elem->perm);
		elem = elem->next;
	}
	printf("\n");
	printf("\n");
	printf("FIN\n");
}
