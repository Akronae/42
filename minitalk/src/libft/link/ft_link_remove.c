/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include <unistd.h>

t_link	*ft_link_remove(t_link *self)
{
	if (self->prev)
		self->prev->next = self->next;
	if (self->next)
		self->next->prev = self->prev;
	self->prev = NULL;
	self->next = NULL;
	return (self);
}
