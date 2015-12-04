/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:03:24 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 22:03:26 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int length;
	int counter;

	length = ft_strlen(s);
	counter = 0;
	while (counter < length)
	{
		*s = '\0';
		s++;
		counter++;
	}
}
