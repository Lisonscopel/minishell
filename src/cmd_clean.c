/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 00:58:08 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:48:00 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	cmd_replace_shortcuts(t_env *env)
{
	int		i;
	int		j;
	char	*tilde;
	char	*tminus;
	char	*res;

	j = 0;
	tilde = ft_strrchr_exclude(env_find_str("HOME", env->env), '=');
	if ((tminus = ft_strrchr_exclude(env_find_str("OLPWD", env->env), '=')) == NULL)
		tminus = env->oldpwd_backup;
	i = 0;
	while (env->cmd[i])
	{
		if (!ft_strncmp(env->cmd[i], "~", 1) && tilde != NULL)
		{
			if (!ft_strcmp(env->cmd[i], "~-"))
			{
				if (tminus == NULL)
					return ;
				res = ft_strdup(tminus);
			}
			else if (!ft_strcmp(env->cmd[i], "~+"))
				res = ft_strdup(".");
			else
				res = ft_strjoin(tilde, ft_strsub(env->cmd[i], 1, ft_strlen(env->cmd[i]) - 1));
			ft_bzero(env->cmd[i], ft_strlen(env->cmd[i]));
			env->cmd[i] = res;
		}
		else if (!ft_strncmp(env->cmd[i], "$", 1))
		{
			res = ft_strsub(env->cmd[i], 1, ft_strlen(env->cmd[i]) - 1);
			while (env->env[j])
			{
				if (!ft_strncmp(res, env->env[j], ft_strlen(res) - 1))
				{
					ft_bzero(res, ft_strlen(res));
					ft_bzero(env->cmd[i], ft_strlen(env->cmd[i]));
					env->cmd[i] = ft_strrchr_exclude(env->env[j], '=');
				}
				j++;
			}
		}
		i++;
	}
}

void	cmd_split(t_env *env)
{
	if (!ft_tablen((env->cmd = ft_strsplit_blank(env->cmdline))))
		return ;
	cmd_replace_shortcuts(env);
	if (!env->bin)
		env->bin = parse_path_to_bin(env_find_str("PATH", env->env));
	if (!ft_isbuiltin(env->cmd, env))
		return ;
	cmd_exec(env->cmd, env->bin, env->env);
	ft_memdel((void *)env->cmd);
}
