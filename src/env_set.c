/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 01:39:31 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:39:33 by lscopel          ###   ########.fr       */
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
		dup = env->env;
		env->env = (char **)malloc(sizeof(char *) * (i + 2));
		i = 0;
		while (dup[i])
		{
			env->env[i] = ft_strdup(dup[i]);
			i++;
		}
		ft_free_tab(dup);
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
	if (!ft_strcmp(env[i], "SHLVL=") && ft_isalpha(new_content[0]))
		env[i] = ft_strjoin(env[i], "0");
	else
		env[i] = ft_strjoin(env[i], new_content);
	free(ptr);
}

char		**env_set(t_env *env, char *var_name, char *new_content)
{
	int		i;

	if (!new_content)
		new_content = ft_strdup("");
	if (!env->env)
	{
		env->env = (char **)malloc(sizeof(char *) * 2);
		env->env[0] = NULL;
		env->env[1] = NULL;
	}
	i = env_find_index(var_name, env->env);
	if (i == -1)
		env_new_var(env, var_name, new_content);
	else
		env_reset_var(env->env, i, new_content);
	return (env->env);
}
