/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                    :+:      :+:    :+:   */
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

t_list *ft_stack_rotate(t_list *self)
{
    if (self->length <= 1)
        return (self);
    self->push(self, self->remove_at(self, 0));
    return (self);
}

t_stacks_op *ft_stacks_op_ra(t_stacks_op *self)
{
	ft_stack_rotate(self->stack_a);
	self->operations->push_long(self->operations, RA);
	return (self);
}

t_stacks_op *ft_stacks_op_rb(t_stacks_op *self)
{
	ft_stack_rotate(self->stack_b);
	self->operations->push_long(self->operations, RB);
	return (self);
}
