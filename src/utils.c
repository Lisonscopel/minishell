/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 22:27:03 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/07 23:32:56 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include <stdio.h>

char	*get_pwd(t_env *env)
{
	char	*pwd;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFLENGHT);
	if ((pwd = getcwd(buff, BUFFLENGHT)) == NULL)
		pwd = ft_strdup(ft_strrchr_exclude(env_find_str("PWD", env->env), '='));
	return (pwd);
}

int		path_in_cmd_is_exec(char **cmd, t_env *env)
{
	int res = 0;
	int	i;
	int j;

	i = ft_tablen(cmd);
	j = 1;
		printf("lecture de variable : %d et %d\n", i, j);
	while (i > j)
	{

		if ((res = access(cmd[j], 0 | F_OK | X_OK)) != 0)
		{
			printf("test de retour de access : %d\n", res);
			res = cmd_bin_path(0, &cmd[j], env->bin, env->env);
			printf("J'ai tout casse ?\n");
		}
		printf("test de retour de access : %s %d\n", cmd[j], res);
		if (res == 0 || !ft_strncmp(cmd[j], ".", 1))
			return (printf("retour de j a %d avec %s\n", j, cmd[j]), j);
		j++;
	}
	return (0);
}

