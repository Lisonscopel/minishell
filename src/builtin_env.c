/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 01:04:37 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 21:39:29 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	**create_env_tmp(char **cmd, int i, int j, int tablen)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * ((tablen + 1) + 1));
	while (cmd[i])
	{
		if (cmd_builtin_export_good_usage(cmd[i]))
		{
			tmp[j] = ft_strdup(cmd[i]);
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	return (tmp);
}

void	cmd_env_i_handle(char **cmd, t_env *env)
{
	int		i;
	int		j;
	int		tablen;

	tablen = ft_tablen(cmd);
	i = tablen;
	j = 0;
	while (i > 0)
	{
		if (cmd[i - 1] && !ft_strcmp(cmd[i - 1], "env")
				&& !ft_strcmp(cmd[i], "-i"))
		{
			env->env = create_env_tmp(++cmd, i, j, tablen);
			return ;
		}
		i--;
	}
}

void	builtin_env(char **cmd, t_env *env)
{
	char	**swp;
	int		j;

	swp = ft_tabdup(env->env);
	if (ft_tablen(cmd) == 1)
		ft_puttab(env->env, 37);
	else
	{
		builtin_export(cmd, env);
		cmd_env_i_handle(cmd, env);
		j = path_in_cmd_is_exec(cmd, env);
		if (j != 0)
			cmd_exec(&cmd[j], env->bin, env->env);
		else if (j == 0 && ft_tablen(swp) != ft_tablen(env->env))
			ft_puttab(env->env, 37);
		else
			error_builtin(cmd, 1);
		ft_free_tab(env->env);
		env->env = swp;
	}
}
