/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:35:29 by lscopel           #+#    #+#             */
/*   Updated: 2015/11/18 23:47:36 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

/*int		do_i_keep_env(char **cmd, t_env *env)
{
	int i = 0;
		while (cmd[i])
		{
			if (!ft_strcmp(cmd[i], "env") && !ft_strcmp(cmd[i + 1], "-i"))
			{
			//	ft_bzero((void *)env->env, sizeof(env->env));
				
				return (-1);
			}

			i++;
		}
		return (0);
}*/

void	builtin_env(char **cmd, t_env *env)
{
	char **swp;

	swp = ft_tabdup(env->env);
//	int ke = do_i_keep_env(cmd, env);
	builtin_export(cmd, env);
	/*	if (ft_tablen(cmd) > 1)
	{
	int exec = cmd_exec(&cmd[ft_tablen(cmd) - 1], env->bin, env->env);
		if (exec < 0)
		{
			(void)ke;
			ft_puttab(env->env, 37);
			ft_bzero((void *)env->env, sizeof(env->env));
			env->env = swp;
		}

		ft_bzero((void *)env->env, sizeof(env->env));
		env->env = swp;
	}
	else
		ft_puttab(env->env, 37);*/

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
