/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_at.c                                    :+:      :+:    :+:   */
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

long ft_stack_at(t_list *self, long index)
{
    return (*self->get_elem(self, index)->data->as_long);
}

long ft_stacks_op_a_at(t_stacks_op *self, long index)
{
	return (ft_stack_at(self->stack_a, index));
}

long ft_stacks_op_b_at(t_stacks_op *self, long index)
{
	return (ft_stack_at(self->stack_b, index));
}