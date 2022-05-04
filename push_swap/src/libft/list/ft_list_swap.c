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
#include "../io/ft_io.h"

void	ft_list_swap(t_list *self, long from_index, long to_index)
{
	t_link *a;
	t_link *b;
	long 	max_index;

	max_index = self->length - 1;
	from_index = ft_math_clamp(from_index, -max_index, max_index);
	to_index = ft_math_clamp(to_index, -max_index, max_index);
	if (from_index < 0)
		from_index = self->length + from_index;
	if (to_index < 0)
		to_index = self->length + to_index;
	if (from_index == to_index)
		return ;
	ft_printfl("from: %d, to: %d", from_index, to_index);
	a = self->remove_at(self, from_index);
	ft_printfl("remove a=%d at from_index=%d => %s{.free()}", a->as_long, from_index, self->join(self, ", "));
	self->insert_at(self, to_index - ft_if_int(to_index > from_index, 1, 0), a);
	ft_printfl("insert a=%d at to_index=%d-%d => %s{.free()}", a->as_long, to_index,  ft_if_int(to_index > from_index, 1, 0), self->join(self, ", "));
	b = self->remove_at(self, to_index + ft_if_int(to_index < from_index, 1, 0));
	ft_printfl("remove b=%d at to_index=%d+%d => %s{.free()}", b->as_long, to_index, ft_if_int(to_index < from_index, 1, 0), self->join(self, ", "));
	self->insert_at(self, from_index - ft_if_int(to_index < from_index, 1, 0), b);
	ft_printfl("insert b=%d at from_index=%d-%d => %s{.free()}", b->as_long, from_index, ft_if_int(to_index < from_index, 1, 0), self->join(self, ", "));
}