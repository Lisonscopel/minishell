/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 22:27:03 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/30 20:37:45 by lscopel          ###   ########.fr       */
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
