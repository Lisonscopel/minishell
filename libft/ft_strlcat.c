/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:00:16 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 22:00:17 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	len_src;
	unsigned int	len_dst;
	int				i;

	len_src = ft_strlen((char *)src);
	len_dst = ft_strlen(dst);
	i = 0;
	if (size <= len_dst)
		return (len_src + size);
	while (len_dst + i < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
