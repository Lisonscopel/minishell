/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 19:19:01 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/30 19:42:57 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	env_shlvl(char *src, t_env *env)
{
	src = ft_itoa(ft_atoi(src) + 1);
	env_set(env, "SHLVL", src);
}

void		env_min(t_env *env)
{
	env->env = NULL;
	env_set(env, "PATH", "toto");
	env_set(env, "SHLVL", "0");
}

void		env_building(char **src, t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	if (!src || !*src)
		env_min(env);
	else
		env->env = ft_tabdup(src);
	env_shlvl(env_find_str("SHLVL", env->env), env);
	env_set(env, "SHELL", "ft_minishell1");
}
