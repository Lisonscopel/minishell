/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 21:43:49 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 22:04:21 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					a;
	unsigned char		*b;
	const unsigned char	*c;

	if (!dst || !src)
		return (NULL);
	a = 0;
	b = (unsigned char*)dst;
	c = (const unsigned char*)src;
	while (n--)
	{
		b[a] = c[a];
		++a;
	}
	return (dst);
}
