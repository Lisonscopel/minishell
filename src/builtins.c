/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:35:29 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/01 00:51:30 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_minishell1.h"


void	cmd_env_i_check(char **cmd, t_env *env)
{
	int				i;
	int				j;
	int				tablen;
	char			**tmp;

	(void)env;
	tablen = ft_tablen(cmd);
	i = tablen;
	j = 0;
	while (i > 0)
	{
		if (cmd[i - 1] && !ft_strcmp(cmd[i - 1], "env") && !ft_strcmp(cmd[i], "-i"))
		{
			tmp = (char **)malloc(sizeof(char *) * (tablen + 1) + 1);
			cmd++;
			while (cmd[i])
			{
				if (cmd_builtin_export_good_usage(cmd[i]))
				{
					tmp[j] = ft_strdup(cmd[i]);
					j++;
				}
				i++;
			}
			tmp[j] = NULL;
			env->env = tmp;
			return ;
		}
		i--;
	}
}

void	builtin_env(char **cmd, t_env *env)
{
	char	**swp;
	int		j;

	swp = ft_tabdup(env->env);
	if (ft_tablen(cmd) == 1)
		ft_puttab(env->env, 37);
	else
	{
		builtin_export(cmd, env);
		cmd_env_i_check(cmd, env);
		j = path_in_cmd_is_exec(cmd, env);
		if (j != 0)
			cmd_exec(&cmd[j],env->bin, env->env);
		else if (j == 0 && cmd_builtin_export_good_usage(cmd[1]))
			ft_puttab(env->env, 37);
		else
			error_builtin(cmd, 1);
		ft_free_tab(env->env);
		env->env = swp;
	}
}

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

int		ft_isbuiltin(char **cmd, t_env *env)
{
	t_fct	*builtin_list;

	list_init_builtins(&builtin_list);
	while (builtin_list != NULL)
	{
		if (cmd[0] && ft_strcmp(builtin_list->id, cmd[0]) == 0)
		{
			builtin_list->ptr_funct(cmd, env);
			return (0);
		}
		builtin_list = builtin_list->next;
	}
	return (1);
}
