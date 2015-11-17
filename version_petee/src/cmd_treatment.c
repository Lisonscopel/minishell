/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 19:15:09 by lscopel           #+#    #+#             */
/*   Updated: 2015/11/17 15:41:33 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include <stdio.h>

void	cmd_exec(char **cmd, char **bin_path, char **env)
{
	int		i;
	int		real_path;
	int		res;
	pid_t	pid;
	char	*cmdpath;

	i = 0;
	if ((pid = fork()) > 0)
		wait(0);
	if (pid == 0)
	{
		if ((real_path = access(*cmd, R_OK)) == 0)
			res = execve(*cmd, cmd, env);
		else if (real_path == -1 && *cmd[0] == '.')
		{
			ft_putstr("minishell: no such file or directory: ");
			ft_putendl(*cmd);
		}
		else
		{
			while (bin_path[i])
			{
				cmdpath = ft_strjoin(bin_path[i], cmd[0]);
				res = execve(cmdpath, cmd, env);
				if (res != -1)
					break ;
				i++;
				free(cmdpath);
			}
			if (res == -1)
				error_cmd_nf(cmd[0], 1);
		}
		exit(0);
	}
}

void	cmd_replace_shortcuts(t_env *env)
{
	int	i;
	int	len;
	char	*tilde;
	char	*tminus;

	i = 0;
	tilde = ft_strrchr_exclude(env_find_str("HOME", env->env), '=');
	if ((tminus = ft_strrchr_exclude(env_find_str("OLPWD", env->env), '=')) == NULL)
		tminus = env->oldpwd_backup;
	while (env->cmd[i])
	{
		len = ft_strlen(env->cmd[i]);
		if (len <= 2 && !ft_strncmp(env->cmd[i], "~", 1))
		{
			if (len == 1 && tilde != NULL)
			{
				ft_bzero(env->cmd[i], ft_strlen(env->cmd[i]));
				env->cmd[i] = ft_strdup(tilde);
			}
			else if (!ft_strcmp(env->cmd[i], "~-") && tminus != NULL)
			{
				ft_bzero(env->cmd[i], ft_strlen(env->cmd[i]));
				env->cmd[i] = ft_strdup(tminus);
			}
			else if (!ft_strcmp(env->cmd[i], "~+"))
			{
				ft_bzero(env->cmd[i], ft_strlen(env->cmd[i]));
				env->cmd[i] = ft_strdup(".");
			}
		}
		i++;
	}
}

void	cmd_split(t_env *env)
{
	if ((env->cmd = ft_strsplit_blank(env->cmdline)) == NULL)
		return ;
	cmd_replace_shortcuts(env);
	if (!env->bin)
		env->bin = parse_path_to_bin(env_find_str("PATH", env->env));
	if (!ft_isbuiltin(env->cmd, env))
		return ;
	cmd_exec(env->cmd, env->bin, env->env);
	ft_memdel((void *)env->cmd);
}

void	cmd_receive(t_env env)
{
	int		ret;

	while (42)
	{
		prompt_display(&env);
		if ((ret = read(0, env.cmdline, 1023)) > 0 && env.cmdline[0] != '\n')
		{
			env.cmdline[ret] = '\0';
			cmd_split(&env);
		}
	}
}
