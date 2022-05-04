/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
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

t_list *ft_stack_push(t_list *dst, t_list *src)
{
    if (src->length == 0)
        return (dst);
    dst->push(dst, src->pop(src));
    return (dst);
}

t_stacks_op *ft_stacks_op_pa(t_stacks_op *self)
{
	ft_stack_push(self->stack_a, self->stack_b);
	self->operations->push_long(self->operations, PA);
	return (self);
}

t_stacks_op *ft_stacks_op_pb(t_stacks_op *self)
{
	ft_stack_push(self->stack_b, self->stack_a);
	self->operations->push_long(self->operations, PB);
	return (self);
}