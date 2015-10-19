/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 22:27:03 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/18 22:58:05 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*get_pwd(t_env *env)
{
	char	*pwd;
	char	buff[BUFFLENGHT];

	pwd = ft_strrchr_exclude(env_find_str("PWD", env->env), '=');
	//if ((pwd = getcwd(buff, BUFFLENGHT)) == NULL)
	ft_putcolorendl(pwd, 31);
	ft_bzero(buff, BUFFLENGHT);
	return (pwd);
}
