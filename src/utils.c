/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 22:27:03 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/01 00:41:43 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

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
	int res;
	int	i;
	int j;

	i = ft_tablen(cmd);
	j = 1;
	while (i > j)
	{
		res = access(cmd[j], R_OK);
		if (res != 0)
		{
			res = cmd_bin_path(0, &cmd[j], env->bin, env->env);
		}
		if (res == 0)
			return (j);
		j++;
	}
	return (0);
}

