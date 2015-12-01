/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 19:15:09 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/01 01:32:55 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int	cmd_bin_path(int exec_indice, char **cmd, char **bin_path, char **env)
{
	int i = 0;
	int res = 0;
	char	*cmdpath;
	while (bin_path[i])
	{
		cmdpath = ft_strjoin(bin_path[i], cmd[0]);
		res = access(cmdpath, R_OK);
		if (res != -1)
		{
			if (exec_indice)
			{
				if ((res = execve(cmdpath, cmd, env)) == -1)
					error_cmd_nf(cmd[0], 1);
				return (-1);
			}
			return (0);
		}
		i++;
		free(cmdpath);
	}
	return (-1);
}

int	cmd_exec(char **cmd, char **bin_path, char **env)
{
	int		i;
	int		real_path;
	int		res;
	pid_t	pid;

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
			res = cmd_bin_path(1, cmd, bin_path, env);
		exit(0);
	}
	return (0);
}


void	cmd_replace_shortcuts(t_env *env)
{
	int	i;
	int	j = 0;
	int	len;
	char	*tilde;
	char	*tminus;
	char	*res;

	tilde = ft_strrchr_exclude(env_find_str("HOME", env->env), '=');
	if ((tminus = ft_strrchr_exclude(env_find_str("OLPWD", env->env), '=')) == NULL)
		tminus = env->oldpwd_backup;
	i = 0;
	while (env->cmd[i])
	{
		len = ft_strlen(env->cmd[i]);
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
		else
			res = NULL;
		i++;
	}
	if (res != NULL)
		free(res);
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
