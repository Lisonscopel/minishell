/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 10:55:25 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/30 20:40:37 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		env_new_var(t_env *env, char *var_name, char *new_content)
{
	int		i;
	char	**dup;

	if (env->env)
	{
		i = ft_tablen(env->env);
		dup = ft_tabdup(env->env);
		ft_free_tab(env->env);
		env->env = (char **)malloc(sizeof(char *) * (i + 2));
		i = 0;
		while (dup[i])
		{
			env->env[i] = ft_strdup(dup[i]);
			i++;
		}
		free(dup);
	}
	else
		i = 0;
	env->env[i] = ft_strjoin(ft_strjoin(var_name, "="), new_content);
	i++;
	env->env[i] = NULL;
}

void		env_reset_var(char **env, int i, char *new_content)
{
	void	*ptr;

	ptr = (void *)env[i];
	env[i] = parse_var_name(env[i], 1);
	env[i] = ft_strjoin(env[i], new_content);
	free(ptr);
}

char		**env_set(t_env *env, char *var_name, char *new_content)
{
	int		i;
	char	**dup;

	if (!env->env)
	{
		env->env = (char **)malloc(sizeof(char *) * 2);
		env->env[0] = NULL;
		env->env[1] = NULL;
	}
	if (!new_content)
		new_content = ft_strdup("");
	i = env_find_index(var_name, env->env);
	dup = NULL;
	if (i == -1)
		env_new_var(env, var_name, new_content);
	else
		env_reset_var(env->env, i, new_content);
	return (env->env);
}
