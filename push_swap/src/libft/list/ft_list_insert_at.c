/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../math/ft_math.h"

t_link	*ft_list_insert_at(t_list *self, size_t insert_index, t_link *insert_elem)
{
	t_link	*elem;

	insert_index = ft_math_clamp(insert_index, 0, self->length);
	if (insert_index == 0)
	{
		self->first->prev = insert_elem;
		insert_elem->next = self->first;
		self->first = insert_elem;
	}
	else
	{
		elem = self->get_elem(self, insert_index - 1);
		elem->insert(elem, insert_elem);
		if (insert_index == self->length)
			self->last = insert_elem;
	}
	self->length++;
	return (insert_elem);
}
