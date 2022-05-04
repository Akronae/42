/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                      :+:      :+:    :+:   */
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

t_list *ft_stack_swap(t_list *self)
{
    self->swap(self, -1, -2);
    return (self);
}

t_stacks_op *ft_stacks_op_sa(t_stacks_op *self)
{
	ft_stack_swap(self->stack_a);
	self->operations->push_long(self->operations, SA);
	return (self);
}

t_stacks_op *ft_stacks_op_sb(t_stacks_op *self)
{
	ft_stack_swap(self->stack_b);
	self->operations->push_long(self->operations, SB);
	return (self);
}