/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../math/ft_math.h"

t_link	*ft_list_remove_at(t_list *self, long remove_index)
{
	t_link	*elem;

	if (remove_index < 0)
		remove_index = self->length + remove_index;
	remove_index = ft_math_clamp(remove_index, 0, self->length - 1);
	elem = self->get_elem(self, remove_index);
	if (remove_index == 0)
		self->first = elem->next;
	if ((size_t) remove_index == self->length - 1)
		self->last = elem->prev;
	elem->remove(elem);
	self->length--;
	return (elem);
}
