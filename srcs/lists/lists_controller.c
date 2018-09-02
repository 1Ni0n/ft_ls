/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:33:14 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/15 17:33:16 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	free_list(S_list *list)
{
	args_node	*elem;
	args_node	*next;

	if (list == NULL)
		return;
	elem = list->head;
	while (elem)
	{
		if (elem->content)
			free(elem->content);
		if (elem->path)
			free(elem->path);
		next = elem->next;
		free(elem);
		elem = next;
	}		
	free(list);
}

void	append_to_list(S_list *list, char *content, char *path)
{
	if (list != NULL)
	{
		args_node *arg;
		if ((arg = malloc(sizeof *arg)))
		{
			arg->content = ft_strdup(content);
			if (path)
				arg->path = ft_strdup(path);
			else
				arg->path = NULL;
			arg->mtime = 0;
			arg->next = NULL;
			if (list->head == NULL)
				list->head = arg;
			if (list->tail == NULL)
			{
				list->tail = arg;
				arg->next = NULL;
			}
			else
			{
				list->tail->next = arg;
				list->tail = arg;
				arg->next = NULL;
			}
			list->length++;
		}
	}
}

void	create_list(dirent *lu, char *path, S_list *list, options opts)
{
	if (lu->d_name[0] == '.' && check_for_opt_a(opts) == 1 &&\
			is_dir_executable(path) == 1)
		append_to_list(list, lu->d_name, path);
	else if (lu->d_name[0] != '.' && is_dir_executable(path)\
			== 1)
		append_to_list(list, lu->d_name, path);
	else if (ft_strcmp(lu->d_name, ".") != 0 &&\
			ft_strcmp(lu->d_name, "..") != 0 && opts.aa == 1)
		append_to_list(list, lu->d_name, path);
	free(path);
}

S_list 	*new_s_list(void)
{
	S_list 	*args;

	if (!(args = malloc(sizeof *args)))
		return (NULL);
	args->length = 0;
	args->head = NULL;
	args->tail = NULL;
	return (args);
}