/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:52:30 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 15:52:32 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
