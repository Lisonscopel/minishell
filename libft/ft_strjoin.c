/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 01:40:37 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 01:40:39 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		total_len;

	total_len = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = (ft_strlen(s1) + ft_strlen(s2));
	new = (char *)malloc(sizeof(char) * (total_len + 1));
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
