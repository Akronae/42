/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include <unistd.h>

t_link	*ft_link_insert(t_link *self, t_link *to_insert)
{
	if (!to_insert)
		return (NULL);
	to_insert->prev = self;
	if (self->next)
	{
		to_insert->next = self->next;
		self->next->prev = to_insert;
	}
	self->next = to_insert;
	return (to_insert);
}
