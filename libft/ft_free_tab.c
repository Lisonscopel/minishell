/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:51:30 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 15:51:31 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int		i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i++])
		free(tab[i]);
	free(tab);
}
