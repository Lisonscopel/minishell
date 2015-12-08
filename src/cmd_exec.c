/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:50:35 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 21:10:51 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		cmd_bin_path(int exe, char **cmd, char **bin, char **env)
{
	int		i;
	int		res;
	char	*cmdpath;

	i = 0;
	res = 0;
	if (!bin || !*bin)
		return (-1);
	while (bin[i])
	{
		cmdpath = ft_strjoin(bin[i], cmd[0]);
		if ((res = access(cmdpath, R_OK)) != -1)
		{
			if (exe)
			{
				res = execve(cmdpath, cmd, env);
				return (-1);
			}
			return (0);
		}
		i++;
		free(cmdpath);
	}
	error_cmd_nf(cmd[0], bin, 4);
	return (-1);
}

void	cmd_handle_errors_or_exec(char **cmd, char **bin_path, char **env)
{
	int		res;
	int		real_path;

	real_path = access(*cmd, F_OK);
	if (!real_path && (res = execve(*cmd, cmd, env)) == -1)
	{
		if ((real_path = access(*cmd, R_OK)) == -1)
			error_cmd_nf(cmd[0], bin_path, 3);
	}
	else if (real_path == -1 && *cmd[0] == '.')
		error_cmd_nf(cmd[0], bin_path, 2);
	else if (res == 0)
		return ;
	else
	{
		res = cmd_bin_path(1, cmd, bin_path, env);
		if (real_path == -1 && res == -1)
			error_cmd_nf(cmd[0], bin_path, 1);
	}
}

int		cmd_exec(char **cmd, char **bin_path, char **env)
{
	int		status;
	pid_t	pid;

	if ((pid = fork()) > 0)
		waitpid(pid, &status, WUNTRACED);
	if (pid == 0)
	{
		cmd_handle_errors_or_exec(cmd, bin_path, env);
		exit(0);
	}
	return (0);
}
