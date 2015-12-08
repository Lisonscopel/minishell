/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 22:27:03 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:42:19 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*get_pwd(t_env *env)
{
	char	*pwd;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFLENGHT);
	if ((pwd = getcwd(buff, BUFFLENGHT)) == NULL)
		pwd = ft_strdup(ft_strrchr_exclude(env_find_str("PWD", env->env), '='));
	return (pwd);
}

int		path_in_cmd_is_exec(char **cmd, t_env *env)
{
	int res;
	int	i;
	int j;

	res = 0;
	i = ft_tablen(cmd);
	j = 1;
	while (i > j)
	{
		if ((res = access(cmd[j], 0 | F_OK | X_OK)) != 0)
			res = cmd_bin_path(0, &cmd[j], env->bin, env->env);
		if (res == 0 || !ft_strncmp(cmd[j], ".", 1))
			return (j);
		++j;
	}
	return (0);
}

int		ft_isbuiltin(char **cmd, t_env *env)
{
	t_fct	*builtin_list;

	list_init_builtins(&builtin_list);
	while (builtin_list != NULL)
	{
		if (cmd[0] && ft_strcmp(builtin_list->id, cmd[0]) == 0)
		{
			builtin_list->ptr_funct(cmd, env);
			return (0);
		}
		builtin_list = builtin_list->next;
	}
	return (1);
}
