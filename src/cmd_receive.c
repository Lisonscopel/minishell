/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_receive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 00:57:37 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:35:16 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	kill_sig(int i)
{
	kill(SIGINT, i);
}

void	cmd_receive(t_env env)
{
	int		ret;

	while (42)
	{
		prompt_display(&env);
		signal(SIGINT, kill_sig);
		if ((ret = read(0, env.cmdline, 1023)) > 0 && env.cmdline[0] != '\n')
		{
			env.cmdline[ret] = '\0';
			cmd_split(&env);
		}
		else if (ret <= 0)
			ft_putendl("");
	}
}
