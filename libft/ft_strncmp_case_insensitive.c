/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_case_insensitive.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:09:17 by lscopel           #+#    #+#             */
/*   Updated: 2015/11/24 18:17:20 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp_case_insensitive(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (ft_toupper(s1[i]) == ft_toupper(s2[i])) && --n > 0)
		i++;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
