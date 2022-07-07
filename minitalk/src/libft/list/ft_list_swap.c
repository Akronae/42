/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../memory/ft_memory.h"
#include "../math/ft_math.h"
#include "../string/ft_string.h"
#include "../io/ft_io.h"
#include <stdio.h>

void	ft_list_swap(t_list *self, long from_index, long to_index)
{
	t_link	*a;
	t_link	*b;
	long	max_index;

	max_index = self->length - 1;
	from_index = ft_math_clamp(from_index, -max_index - 1, max_index);
	to_index = ft_math_clamp(to_index, -max_index - 1, max_index);
	if (from_index < 0)
		from_index = self->length + from_index;
	if (to_index < 0)
		to_index = self->length + to_index;
	if (from_index == to_index)
		return ;
	if (from_index > to_index)
		ft_swap_long(&from_index, &to_index);
	a = self->remove_at(self, from_index);
	self->insert_at(self, to_index - 1, a);
	b = self->remove_at(self, to_index);
	self->insert_at(self, from_index, b);
}
