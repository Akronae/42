/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_reverse_rotate.c                          :+:      :+:    :+:   */
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

t_list	*ft_stack_reverse_rotate(t_list *self)
{
	if (self->length <= 1)
		return (self);
	self->push(self, self->remove_at(self, 0));
	return (self);
}

t_stacks_op	*ft_stacks_op_rra(t_stacks_op *self)
{
	ft_stack_reverse_rotate(self->stack_a);
	self->operations->push_long(self->operations, RRA);
	return (self);
}

t_stacks_op	*ft_stacks_op_rrb(t_stacks_op *self)
{
	ft_stack_reverse_rotate(self->stack_b);
	self->operations->push_long(self->operations, RRB);
	return (self);
}
