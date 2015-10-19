/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 22:01:09 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/11 23:13:09 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	ft_realloc(void **ptr, size_t slen, size_t nlen)
{
	void	*new;

	if (!ptr)
		return ;
	new = ft_malloc(nlen);
	ft_memcpy(new, *ptr, slen);
	if (*ptr)
		free(*ptr);
	*ptr = new;
}
