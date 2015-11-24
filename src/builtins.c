/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:35:29 by lscopel           #+#    #+#             */
/*   Updated: 2015/11/25 00:13:29 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	if (ft_tablen(cmd) > 1 && !ft_strncmp(cmd[ft_tablen(cmd) - 1], "./", 2))
	{
		cmd_exec(&cmd[ft_tablen(cmd) - 1], env->bin, env->env);
		ft_bzero((void *)env->env, sizeof(env->env));
		env->env = swp;
	}
	else if (ft_tablen(cmd) > 1)
	{
		ft_puttab(env->env, 37);
		ft_bzero((void *)env->env, sizeof(env->env));
		env->env = swp;
	}
	else
		ft_puttab(env->env, 37);
*/

#include "ft_minishell1.h"

void	builtin_env(char **cmd, t_env *env)
{
	char **swp;
	int res;
	int	i;
	int	j;

	swp = ft_tabdup(env->env);
	i = ft_tablen(cmd) - 1;
	j = 1;
	if (ft_tablen(cmd) == 1)
		ft_puttab(env->env, 37);
	else
	{
		while (i > 0)
		{
			if (env->cmd[i - 1] && !ft_strcmp(env->cmd[i - 1], "env") && !ft_strcmp(env->cmd[i], "-i"))
			{
				while (j < i)
				{
				/*	ft_bzero(env->cmd[j], ft_strlen(env->cmd[j]));
					free(env->cmd[j]);
					*/

					free(env->cmd[j]);
					j++;
				}
			}
		}
		builtin_export(cmd, env);
		if ((res = access(cmd[ft_tablen(cmd) - 1], R_OK)) == -1)
			error_builtin(cmd, 1);
		else
			res = execve(*cmd, cmd, env->env);
	}
}

void	builtin_exit(char **cmd, t_env *env)
{
	int	i;

	free(env->env);
	if ((i = ft_tablen(cmd)) > 2)
		ft_putendl("exit: too many arguments");
	else if (i == 2 && ft_atoi(cmd[1]))
		exit(ft_atoi(cmd[1]));
	else
		exit(0);
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
