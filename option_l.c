/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:13:32 by aguillot          #+#    #+#             */
/*   Updated: 2018/06/19 15:12:39 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void 	set_majorminor(args_node *elem, struct stat sb)
{
	elem->major = major(sb.st_rdev);
	elem->minor = minor(sb.st_rdev);
}

void	get_longest(args_node *elem, longest *longest)
{
	if (ft_nblen(elem->hardlinks) > longest->hardlinks)
		longest->hardlinks = ft_nblen(elem->hardlinks);
	if (elem->uid != NULL && ft_strlen(elem->uid) > longest->uid)
		longest->uid = ft_strlen(elem->uid);
	if (elem->gid != NULL && ft_strlen(elem->gid) > longest->gid)
		longest->gid = ft_strlen(elem->gid);
	if (ft_nblen(elem->size) > longest->size)
		longest->size = ft_nblen(elem->size);
}

void	get_perm(args_node *elem)
{
	char		*path;
	struct stat sb;
	struct stat sb2;
	time_t		good_time;

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
		elem->mtime = sb.st_mtime;
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
	elem->perm[10] = '\0';
	free(path);
	if (elem->perm[0] == 'c' || elem->perm[0] == 'b')
		set_majorminor(elem, sb);
}

void	get_correct_date(args_node *elem)
{
	char 	*correct_date;
	int 	i;
	int		j;
	time_t 	actual_time;
	time_t	diff;

	i = 4;
	j = 0;
	if ((actual_time = time(NULL)) == -1)
		return;	
	correct_date = (char*)malloc(sizeof(char) * (13));
	while (i < 16)
		correct_date[j++] = elem->mtimefull[i++];
	correct_date[j] = '\0';
	free(elem->mtimefull);
	elem->mtimefull = ft_strdup(correct_date);
	if ((diff = elem->mtime - actual_time) >= 15768000 || diff <= -15768000)
	{
		//printf("%s ", elem->content);
		diff = 1970 + (elem->mtime / 31557600);
		//printf("DIFF: %ld\n", diff);
		elem->mtimefull[7] = ' ';
		elem->mtimefull[8] = (diff / 1000) + '0';
		elem->mtimefull[9] = ((diff / 100) % 10) + '0';
		elem->mtimefull[10] = ((diff / 10) % 10) + '0';
		elem->mtimefull[11] = (diff % 10) + '0';
	}
	free(correct_date);
}

int get_infos(args_node *elem)
{
	char			*path;
	struct stat 	sb;
	struct passwd 	*p;
	struct group 	*p2;
	int 			link;
	char			symlink[255];
	char 			*tmp;

	if (elem->path == NULL)
		path = ft_strdup(elem->content);
	else
	{
		tmp = path;
		path = ft_strdup(elem->path);
		//free(path);
	}
	elem->symlink = NULL;
	if (lstat(path, &sb) == -1)
	{
		printf("ELEM: %s\n", path);
		//printf("ELEM: %s, LSTAT: %d\n", path, lstat(path, &sb));
		perror("");
		return (0);
	}
	if (S_ISLNK(sb.st_mode) == 1)
	{
		if ((link = readlink(path, symlink, 255)) != -1)
		{
			symlink[link] = '\0';
			elem->symlink = ft_strdup(symlink);
		}
	}
	if ((p = getpwuid(sb.st_uid)) != NULL)
		elem->uid = ft_strdup(p->pw_name);
	else
		elem->uidd = sb.st_uid;
	if ((p2 = getgrgid(sb.st_gid)) != NULL)
		elem->gid = ft_strdup(p2->gr_name);
	else
		elem->gidd = sb.st_gid;
	elem->hardlinks = sb.st_nlink;
	elem->mtimefull = ft_strdup(ft_strtrim(ctime(&sb.st_mtime)));
	get_perm(elem);	
	get_correct_date(elem);
	elem->size = sb.st_size;
	elem->nb_of_blocks = sb.st_blocks;
//	free(path);
	return (1);
}

void	option_l(S_list *list)
{
	args_node 	*elem;
	longest 	longest;

	elem = list->head;
	longest.hardlinks = 0;
	longest.uid = 0;
	longest.gid = 0;
	longest.size = 0;
	while (elem)
	{
		if (get_infos(elem) == 1)
			get_longest(elem, &longest);
		else
			elem->content = NULL;
		elem = elem->next;
	}
	print_list_l(list, &longest);
}