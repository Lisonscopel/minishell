/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 19:15:09 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:37:38 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int	cmd_bin_path(int exec_indice, char **cmd, char **bin_path, char **env)
{
	int		i;
	int		res;
	char	*cmdpath;

	i = 0;
	res = 0;
	if (!bin_path || !*bin_path)
		return (-1);
	while (bin_path[i])
	{
		cmdpath = ft_strjoin(bin_path[i], cmd[0]);
		res = access(cmdpath, 0 | F_OK | X_OK);
		if (res != -1)
		{
			if (exec_indice)
			{
				res = execve(cmdpath, cmd, env);
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
	int		real_path;
	int		res;
	int		status;
	pid_t	pid;

	if ((pid = fork()) > 0)
		waitpid(pid, &status, WUNTRACED);
	if (pid == 0)
	{
		real_path = access(*cmd, R_OK);
		if (!real_path && (res = execve(*cmd, cmd, env)) == -1)
			error_cmd_nf(cmd[0], 3);
		else if (real_path == -1 && *cmd[0] == '.')
			error_cmd_nf(cmd[0], 2);
		else if ((res = cmd_bin_path(1, cmd, bin_path, env)) == -1)
			error_cmd_nf(cmd[0], 4);
		exit(0);
	}
	return (0);
}
