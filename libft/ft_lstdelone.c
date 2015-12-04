/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:04:30 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/03 22:04:31 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == NULL || !(*alst) || !(del))
		return ;
	del(&((*alst)->content), (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
