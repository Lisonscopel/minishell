/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 01:41:54 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:41:56 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **src)
{
	int		i;
	char	**dest;

	i = 0;
	dest = (char **)malloc(sizeof(char *) * (ft_tablen(src) + 1));
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		++i;
	}
	dest[i] = NULL;
	return (dest);
}
