/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 10:49:28 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/16 11:10:51 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		cmd_builtin_export_good_usage(char *cmd)
{
	/*	if (!ft_isalpha(cmd[0]))
	 *			return (error_cmd_nf(cmd, 2));*/
	if (ft_strchr(cmd, '=') != NULL)
		return (1);
	return (0);
}

#include <stdio.h>
int		builtin_export(char **cmd, t_env *env)
{
	char	**args;

	if (*cmd)
	{
		if (ft_strcmp(*cmd, "export") || ft_strcmp(*cmd, "env"))
		{
			if (cmd_builtin_export_good_usage(*cmd) != 0) 
			{
				if (*cmd[0] == '=')
				{
					ft_putendl("Don't mess with me you serial bullshiter");
					return (-1);
				}
				args = ft_strsplit(*cmd, '=');
//			ft_putstr_fd("\033[0;32;40mFIRST : ", 2);
//			ft_putstr_fd(*cmd, 2);
//			ft_putstr_fd("\n", 2);
				env->env = env_set(env, args[0], args[1]);
//			ft_putstr_fd("\033[0;34;40mSECOND : ", 2);
//			ft_putstr_fd(*cmd, 2);
//			ft_putstr_fd("\n\n", 2);
//			ft_putstr_fd("0x\033[0;32;31mDER : ", 2);
//			ft_putstr_fd(cmd[1], 2);
//			ft_putstr_fd("\n", 2);
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
