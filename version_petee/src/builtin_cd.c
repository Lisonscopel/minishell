/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 15:15:48 by lscopel           #+#    #+#             */
/*   Updated: 2015/11/17 15:34:29 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*builtin_cd_specials(char **cmd, t_env *env)
{
	char		*str;

	str = NULL;
	if (ft_tablen(cmd) == 1)
	{
		if ((str = env_find_str("HOME", env->env)) != NULL)
			str = ft_strrchr_exclude(str, '=');
	}
	else if (!ft_strcmp(cmd[1], "-"))
		str = env->oldpwd_backup;
	else if (!ft_strcmp(cmd[1], "/"))
		str = "/";
	else
		return (NULL);
	return (str);
}

void	builtin_cd_swap(char **cmd, t_env *env)
{
	char	*pwd;
	char	*dir;
	int		res;

	pwd = get_pwd(env);
	if (ft_strstr(pwd, cmd[1]) == NULL)
		error_builtin_cd(cmd, 3);
	else
	{
		dir = ft_strreplace(pwd, cmd[1], cmd[2]);
		res = chdir(dir);
		if (res == -1)
		{
			cmd[1] = dir;
			error_builtin_cd(cmd, 1);
		}
	}
}

void	builtin_cd_simple_param(char **cmd, t_env *env)
{
	int res;

	if (ft_tablen(cmd) == 1 || !ft_strncmp(cmd[1], "-", 1))
		res = chdir(builtin_cd_specials(cmd, env));
	else
	{
		res = chdir(cmd[1]);
	}
	if (res == -1)
		error_builtin_cd(cmd, 1);
}

int		builtin_cd(char **cmd, t_env *env)
{
	char	*pwd;

	pwd = get_pwd(env);
	if (ft_tablen(cmd) > 3)
	{
		error_builtin_cd(cmd, 2);
		return (-1);
	}
	else if (ft_tablen(cmd) <= 2)
		builtin_cd_simple_param(cmd, env);
	else
		builtin_cd_swap(cmd, env);
	env->oldpwd_backup = ft_strdup(pwd);
	env->env = env_set(env, "OLDPWD", pwd);
	pwd = get_pwd(env);
	env->env = env_set(env, "PWD", pwd);
	return (0);
}
