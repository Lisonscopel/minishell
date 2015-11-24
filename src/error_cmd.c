/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 10:49:37 by lscopel           #+#    #+#             */
/*   Updated: 2015/11/24 21:06:30 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*error_print(char *s1, char *s2, char *s3)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	result = ft_strjoin(result, s3);
	ft_putendl(result);
	free(result);
	return (result);
}

int		error_cmd_nf(char *cmd, int error)
{
//	char	**cmd_parsed;
	if (error == 1)
		error_print("ft_minishell1: ", "command not found: ", cmd);
/*	if (error == 2)
	{
		cmd_parsed = ft_strsplit_blank(cmd);
		if (ft_strrchr(cmd_parsed[1], '=') == NULL)
		{
			ft_putcolorendl("1", 31);
			shell = join_params("export", "not an identifier", cmd_parsed[1]);
		}
		else
			shell = join_params("export", "not an identifier", parse_var_name(cmd_parsed[1], 0));
		free(shell);
	}*/
	else
		return (-1);
	return (0);
}

void	error_builtin(char **cmd, int error)
{
	char	*perm;

	if (error == 1)
	{
		perm = parse_permissions(cmd[1]);
		if (perm && perm[0] == 'd' && (perm[1] == '-' || perm[3] == '-'))
			error_print(cmd[0], ": permission denied: ", cmd[1]);
		else if (perm && perm[0] == '-')
			error_print(cmd[0], ": not a directory: ", cmd[1]);
		else
			error_print(cmd[0], ": no such file or directory: ", cmd[1]);
	}
	if (error == 2)
		error_print(cmd[0], ": too many arguments", "");
	if (error == 3)
		error_print(cmd[0], ": string not in pwd: ", cmd[1]);
}
