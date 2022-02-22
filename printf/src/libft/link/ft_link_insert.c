/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"

t_link	*ft_link_insert(t_link *self)
{
	t_link	*new_elem;

	new_elem = new_link();
	new_elem->prev = self;
	if (self->next)
	{
		new_elem->next = self->next;
		self->next->prev = new_elem;
	}
	self->next = new_elem;
	return (new_elem);
}
