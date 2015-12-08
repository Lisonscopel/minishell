/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 01:01:52 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:24:18 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	builtin_exit(char **cmd, t_env *env)
{
	int	i;

	free(env->env);
	if ((i = ft_tablen(cmd)) > 2)
		ft_putendl("exit: too many arguments");
	else if (i == 2 && ft_atoi(cmd[1]))
		exit(ft_atoi(cmd[1]));
	else
		exit(0);
}
