/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 12:50:26 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/17 11:48:36 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		builtin_unset(char **cmd, t_env *env)
{
	int		i;
	int		j;
	char	**var_parsed;

	i = 1;
	while (cmd[i])
	{
		j = 0;
		while (env->env[j])
		{
			var_parsed = ft_strsplit(env->env[j], '=');
			/*if (!ft_strcmp(var_parsed[0], "OLDPWD"))
				env->oldpwd_backup = ft_strdup()*/
			if (!ft_strncmp(cmd[i], var_parsed[0], ft_strlen(var_parsed[0])))
			{
				while (env->env[j])
				{
					if (env->env[j] && env->env[j + 1])
					{
						env->env[j] = ft_strdup(env->env[j + 1]);
						ft_bzero(env->env[j + 1], ft_strlen(env->env[j + 1]));
					}
					else
						env->env[j] = NULL;
					j++;
				}
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
