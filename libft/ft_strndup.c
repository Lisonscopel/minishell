/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 21:55:26 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 21:55:27 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, int nb)
{
	char *res;

	res = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (res == NULL)
		return (NULL);
	ft_strncpy(res, s1, nb);
	return (res);
}
