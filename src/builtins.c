/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:35:29 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/18 00:16:08 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

/*
   char		*builtin_check_permissions(char *path)
   {
   char	*perm;

   perm = parse_permissions(path);
   if (perm == NULL)
   ft_putcolorendl("NOPE", 31);
   if (ft_strncmp(path, "d", 1))
   return (ft_strjoin("cd: not a directory: ", path));
   return (NULL);
   }*/

char			*builtin_cd_specials(char **cmd, t_env *env)
{
	char		*str;

	str = NULL;
	if (ft_tablen(cmd) == 1 || !ft_strcmp(cmd[1], "~"))
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

char		*ft_strreplace2(char *src, char *occ, char *new)
{
	(void)new;
	int i = 0;
	int j = 0;
	int k = 0;
	int	l = 0;
	char	*r;

	r = (char *)malloc(sizeof(char) * 1023);
	while (src[i])
	{
		if (src[i] == occ[j])
		{
			l = i;
			while (src[i++] == occ[j++])
				;
			if (occ[j] == '\0')
				break ;
			else
				j = 0;
			i = l;
		}
			r[k++] = src[i++];
	}
	ft_putcolorendl(r, 31);
	j = 0;
	while (new[j])
		r[k++] = new[j++];
	if (src)
	{
		r[k++] = src[i++];
		while (src[i])
			r[k++] = src[i++];
	}
	r[k++] = '/';
	ft_putendl(r);
	r[k] = '\0';
	return (r);
}

void		builtin_cd_swap(char **cmd, t_env *env)
{
	char	*pwd;
	char	buf[BUFFLENGHT];
	char	*dir;
	int		res;
	(void)env;

	pwd = getcwd(buf, BUFFLENGHT);
	if (ft_strstr(pwd, cmd[1]) == NULL)
		error_builtin_cd(cmd, 3);
	else
	{
		dir = ft_strreplace2(pwd, cmd[1], cmd[2]);
		res = chdir(dir);
	}
}

void		builtin_cd_simple_param(char **cmd, t_env *env)
{
	int res;

	if (ft_tablen(cmd) == 1 || (!ft_isalpha(cmd[1][0]) && ft_strncmp(cmd[1], ".", 1)))
		res = chdir(builtin_cd_specials(cmd, env));
	else
		res = chdir(cmd[1]);
	if (res == -1)
		error_builtin_cd(cmd, 1);
}

int			builtin_cd(char **cmd, t_env *env)
{
	char	*pwd;
	char	buf[1024];

	pwd = getcwd(buf, 1024);
	if (ft_tablen(cmd) > 3)
	{
		error_builtin_cd(cmd, 2);
		return (-1);
	}
	if (ft_tablen(cmd) <= 2)
		builtin_cd_simple_param(cmd, env);
	else
		builtin_cd_swap(cmd, env);
	env->oldpwd_backup = ft_strdup(pwd);
	env->env = env_set(env, "OLDPWD", pwd);
	ft_bzero(buf, 1024);
	pwd = getcwd(buf, 1024);
	env->env = env_set(env, "PWD", pwd);
	return (0);
}

void		builtin_env(char **cmd, t_env *env)
{
	char **swp;

	swp = ft_tabdup(env->env);
	builtin_export(cmd, env);
	if (ft_tablen(cmd) > 1 && !ft_strncmp(cmd[ft_tablen(cmd) - 1], "./", 2))
	{
		cmd_exec(&cmd[ft_tablen(cmd) - 1], env->bin, env->env);
	}
	else if (ft_tablen(cmd) > 1)
	{
		ft_puttab(env->env, 37);
		ft_bzero((void *)env->env, sizeof(env->env));
		env->env = swp;
	}
	else
		ft_puttab(env->env, 37);
}


void	builtin_exit(char **cmd, t_env *env)
{
	(void)env;
	int	i;

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
