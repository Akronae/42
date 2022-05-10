/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_op_set_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks_op.h"
#include "../libft/memory/ft_memory.h"
#include <stdlib.h>

t_stacks_op *ft_stacks_op_set_stack(t_stacks_op *self, t_list **old_stack, t_list *new_stack)
{
	t_list	*a_sorted;

	(*old_stack)->free(*old_stack);
	*old_stack = new_stack;
	a_sorted = self->stack_a->sort(self->stack_a, T_TYPE_LONG);
	self->min = *a_sorted->first->as_long;
	self->max = *a_sorted->last->as_long;
	self->med = *a_sorted->get_elem(a_sorted, a_sorted->length / 2)->as_long;
	a_sorted->free(a_sorted);
	return (self);
}

t_stacks_op *ft_stacks_op_set_stack_a(t_stacks_op *self, t_list *new_stack)
{
	return (ft_stacks_op_set_stack(self, &self->stack_a, new_stack));
}

t_stacks_op *ft_stacks_op_set_stack_b(t_stacks_op *self, t_list *new_stack)
{
	return (ft_stacks_op_set_stack(self, &self->stack_b, new_stack));
}
