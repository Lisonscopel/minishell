/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 21:08:23 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/15 15:36:21 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			main(int ac, char **av, char **ep)
{
	t_env	env;
	//extern char	**environ;

	(void)av;
	(void)ac;
	//env_building(environ, &env);
	env_building(ep, &env);
	cmd_receive(env);
	return (0);
}
