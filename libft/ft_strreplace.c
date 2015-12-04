/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 19:40:33 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 21:54:35 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			find_first_occur(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*s_new;

	i = 0;
	j = 0;
	s_new = (char *)s1;
	if (s2 == NULL || s2[j] == '\0')
		return (-1);
	while (s1[i] != '\0')
	{
		k = i;
		while (s2[j] == s1[k] && s2[j] != '\0')
		{
			k++;
			j++;
		}
		if (s2[j] == '\0')
			return (i);
		j = 0;
		i++;
	}
	return (0);
}

char		*ft_strreplace(char *src, char *occ, char *new)
{
	int		len;
	char	*res;
	int		index;

	if ((len = (ft_strlen(src) - ft_strlen(occ)) + ft_strlen(new) + 1) <= 0)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	index = find_first_occur(src, occ);
	res = ft_strsub(src, 0, index);
	res = ft_strcat(res, new);
	if (src[index = index + ft_strlen(occ)] == '\0')
		return (res);
	res = ft_strcat(res, ft_strsub(src, index, ft_strlen(src) - index));
	return (res);
}
