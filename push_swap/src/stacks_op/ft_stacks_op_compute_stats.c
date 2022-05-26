/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_op_compute_stats.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks_op.h"
#include "../libft/memory/ft_memory.h"
#include "../libft/math/ft_math.h"
#include "../libft/logic/ft_logic.h"
#include <stdlib.h>

t_stacks_op *ft_stacks_op_compute_stats(t_stacks_op *self)
{
	t_list	*a_sorted;
	t_list	*b_sorted;

	a_sorted = self->stack_a->sort(self->stack_a, T_TYPE_LONG);
	b_sorted = self->stack_b->sort(self->stack_b, T_TYPE_LONG);
	if (a_sorted->length > 0)
		self->min_a = *a_sorted->first->as_long;
	if (b_sorted->length > 0)
		self->min_b = *b_sorted->first->as_long;
	if (a_sorted->length > 0 || b_sorted->length > 0)
		self->min = ft_if_int(b_sorted->length == 0 || self->min_a < self->min_b, self->min_a, self->min_b);
	if (a_sorted->length > 0)
		self->max_a = *a_sorted->last->as_long;
	if (b_sorted->length > 0)
		self->max_b = *b_sorted->last->as_long;
	if (a_sorted->length > 0 || b_sorted->length > 0)
		self->max = ft_if_int(b_sorted->length == 0 || self->max_a > self->max_b, self->max_a, self->max_b);
	if (a_sorted->length > 0)
		self->med = *a_sorted->get_elem(a_sorted, a_sorted->length / 2)->as_long;
	self->stacks_length = self->stack_a->length + self->stack_b->length;
	a_sorted->free(a_sorted);
	b_sorted->free(b_sorted);
	return (self);
}
