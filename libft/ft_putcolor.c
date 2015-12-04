/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 21:59:13 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 21:59:25 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcolor(char *str, int color)
{
	ft_putstr("\033[");
	ft_putnbr(color);
	ft_putstr("m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}
