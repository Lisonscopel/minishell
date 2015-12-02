/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 21:08:23 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/30 20:47:20 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			main(int ac, char **av, char **ep)
{
	t_env	env;

	(void)av;
	(void)ac;
	//env_building(environ, &env);
	env_building(ep, &env);
	cmd_receive(env);
	return (0);
}
