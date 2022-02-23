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

t_link	*ft_link_insert(t_link *self)
{
	t_link	*new_elem;

	new_elem = new_link();
	if (!new_elem)
		return (NULL);
	new_elem->prev = self;
	if (self->next)
	{
		new_elem->next = self->next;
		self->next->prev = new_elem;
	}
	self->next = new_elem;
	return (new_elem);
}
