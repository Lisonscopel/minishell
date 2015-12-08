/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 20:35:52 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 21:12:42 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	prompt_display(t_env *env)
{
	char *pwd;
	char buff[BUFFLENGHT];

	(void)env;
	if ((pwd = getcwd(buff, BUFFLENGHT)) == NULL)
		pwd = ft_strdup("/[FORBIDDEN_DIR]");
	pwd = ft_strrchr_exclude(pwd, '/');
	if (!ft_strcmp(pwd, "lscopel"))
		pwd = ft_strdup("~");
	pwd = ft_strjoin(pwd, " > ");
	ft_putcolor(pwd, 33);
	bzero(buff, BUFFLENGHT);
	free(pwd);
}
