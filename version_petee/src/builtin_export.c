/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 10:49:28 by lscopel           #+#    #+#             */
/*   Updated: 2015/11/18 23:48:33 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		cmd_builtin_export_good_usage(char *cmd)
{
/*	if (!ft_isalpha(cmd[0]))
		return (error_cmd_nf(cmd, 2));*/
	if (ft_strchr(cmd, '=') != NULL)
		return (1);
	return (0);
}

int		builtin_export(char **cmd, t_env *env)
{
	char	**args;

	if (*cmd)
	{
		if (cmd[0] && cmd[1] && !ft_strcmp(cmd[0], "env") && !ft_strcmp(cmd[1], "env"))
		{
		cmd++;
		builtin_export(cmd, env);
		}
		if (cmd[0] && cmd[1] && !ft_strcmp(cmd[0], "env") && !ft_strcmp(cmd[1], "-i"))
		{
			ft_bzero((void*)env->env, sizeof(env->env));
			ft_bzero(cmd[1], ft_strlen(cmd[1]));
			ft_puttab(cmd, 32);
			builtin_export(cmd, env);
		}
		else if (ft_strcmp(*cmd, "export") || ft_strcmp(*cmd, "env"))
		{
			if (cmd_builtin_export_good_usage(*cmd) != 0)
			{
				if (*cmd[0] == '=')
				{
					ft_putendl("Don't mess with me you serial bullshiter");
					return (-1);
				}
				args = ft_strsplit(*cmd, '=');
				env->env = env_set(env, args[0], args[1]);
				if (args[1])
				{
					free(args[0]);
					free(args[1]);
				}
			}
		}
		cmd++;
		builtin_export(cmd, env);
	}
	return (0);
}
