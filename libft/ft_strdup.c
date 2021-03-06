/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 01:40:22 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:40:24 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *res;

	if (!(s1))
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, s1);
	return (res);
}
