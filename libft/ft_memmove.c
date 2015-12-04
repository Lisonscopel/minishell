/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:02:41 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 22:02:42 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!(dst))
		return (dst);
	if (!(src))
		return (dst);
	s = (const char *)src;
	d = (char *)dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	s += len;
	d += len;
	while (len)
	{
		len--;
		*--d = *--s;
	}
	return (dst);
}
