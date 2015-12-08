/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 10:49:37 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 21:51:20 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*error_print(const char *s1, const char *s2, const char *s3)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	result = ft_strjoin(result, s3);
	ft_putendl(result);
	free(result);
	return (result);
}

int		error_cmd_nf(char *cmd, char **bin, const unsigned int err)
{
	if (!bin || !*bin)
		ft_putcolorendl("[ERROR] PATH not defined", 31);
	else if (err == 1)
		error_print("ft_minishell1: ", "command not found: ", cmd);
	else if (err == 2)
		error_print("ft_minishell1: ", "no such file or directory: ", cmd);
	else if (err == 3)
		error_print("ft_minishell1: ", "permission denied: ", cmd);
	else
		return (-1);
	return (err);
}

void	error_builtin(char **cmd, const unsigned int error)
{
	char	*perm;

	perm = NULL;
	if (error == 1)
	{
		if (cmd[1])
			perm = parse_permissions(cmd[1]);
		if (perm && perm[0] == 'd' && (perm[1] == '-' || perm[3] == '-'))
			error_print(cmd[0], ": permission denied: ", cmd[1]);
		else if (perm && perm[0] == '-')
			error_print(cmd[0], ": not a directory: ", cmd[1]);
		else if (ft_strcmp(cmd[1], "-i"))
			error_print(cmd[0], ": no such file or directory: ", cmd[1]);
		else
			error_print(cmd[0], ": no such file or directory: ", cmd[2]);
	}
	if (error == 2)
		error_print(cmd[0], ": too many arguments", "");
	if (error == 3)
		error_print(cmd[0], ": string not in pwd: ", cmd[1]);
}
