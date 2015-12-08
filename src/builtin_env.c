/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 01:04:37 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:47:32 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	cmd_env_i_check(char **cmd, t_env *env)
{
	int		i;
	int		j;
	int		tablen;
	char	**tmp;

	tablen = ft_tablen(cmd);
	i = tablen;
	j = 0;
	while (i > 0)
	{
		if (cmd[i - 1] && !ft_strcmp(cmd[i - 1], "env") && !ft_strcmp(cmd[i], "-i"))
		{
			tmp = (char **)malloc(sizeof(char *) * ((tablen + 1) + 1));
			cmd++;
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
			env->env = tmp;
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
		cmd_env_i_check(cmd, env);
		j = path_in_cmd_is_exec(cmd, env);
		if (j != 0)
			cmd_exec(&cmd[j], env->bin, env->env);
		else if (j == 0 && cmd_builtin_export_good_usage(cmd[1]))
			ft_puttab(env->env, 37);
		else
			error_builtin(cmd, 1);
		ft_free_tab(env->env);
		env->env = swp;
	}
}
