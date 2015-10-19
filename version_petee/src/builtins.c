/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:35:29 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/18 15:17:45 by lscopel          ###   ########.fr       */
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
