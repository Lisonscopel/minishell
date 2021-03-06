/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 19:19:01 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:31:35 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	env_shlvl(char *src)
{
	int		i;
	int		j;
	int		lvl;

	if (src)
	{
		i = 0;
		lvl = 0;
		while (ft_isdigit(src[i]) == 0)
			i++;
		j = i;
		while (src && ft_isdigit(src[i]))
		{
			lvl = lvl * 10 + ft_atoi(&src[i]);
			i++;
		}
		src[j] = (*ft_itoa(lvl + 1));
	}
}

void	env_min(t_env *env)
{
	env->env = NULL;
	env_set(env, "SHLVL", "1");
}

void	env_building(char **src, t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	if (!src || !*src)
		env_min(env);
	else
	{
		env->env = ft_tabdup(src);
		if (!env_find_str("SHLVL", env->env))
			env_set(env, "SHLVL", "1");
		else
			env_shlvl(env_find_str("SHLVL", env->env));
	}
	env_set(env, "SHELL", "minishell");
}
