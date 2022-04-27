/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../memory/ft_memory.h"
#include "../math/ft_math.h"
#include "../logic/ft_logic.h"

void	ft_list_swap(t_list *self, size_t from_index, size_t to_index)
{
	t_link *a;
	t_link *b;

	from_index = ft_math_clamp(from_index, 0, self->length - 1);
	to_index = ft_math_clamp(to_index, 0, self->length - 1);
	if (from_index == to_index)
		return ;
	a = self->remove_at(self, from_index);
	self->insert_at(self, to_index - ft_if_int(from_index < to_index, 1, 0), a);
	b = self->remove_at(self, to_index + ft_if_int(to_index < from_index, 1, 0));
	self->insert_at(self, from_index - ft_if_int(to_index < from_index, 1, 0), b);
}
