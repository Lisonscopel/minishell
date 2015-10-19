/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:17:03 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/16 11:22:05 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

t_fct	*list_add(t_fct **list, void *id, void *(*ptr_funct)())
{
	t_fct	*new;
	t_fct	*tmp;

	tmp = *list;
	new = (t_fct *)malloc(sizeof(t_fct));
	new->id = id;
	new->ptr_funct = (void *)ptr_funct;
	new->next = NULL;
	if (*list == NULL)
		return (new);
	else
	{
		while ((*list)->next != NULL)
			*list = (*list)->next;
	}
	(*list)->next = new;
	return (tmp);
}

void	list_init_builtins(t_fct **list)
{
	*list = NULL;
	*list = list_add(list, "cd", (void *)builtin_cd);
	*list = list_add(list, "chdir", (void *)builtin_cd);
	*list = list_add(list, "quit", (void *)builtin_exit);
	*list = list_add(list, "exit", (void *)builtin_exit);
	*list = list_add(list, "env", (void *)builtin_env);
	*list = list_add(list, "unset", (void *)builtin_unset);
	*list = list_add(list, "export", (void *)builtin_export);
	*list = list_add(list, "setenv", (void *)builtin_export);
}
