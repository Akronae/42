/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"
#include "libft/io/ft_io.h"
#include "libft/list/ft_list.h"
#include "libft/string/ft_string.h"
#include "libft/number/ft_number.h"
#include "libft/memory/ft_memory.h"
#include "libft/math/ft_math.h"
#include "libft/logic/ft_logic.h"
#include "libft/map/ft_map.h"
#include "stacks_op/ft_stacks_op.h"

void	move_b_elem_to_top(t_stacks_op *op, size_t elem_index)
{
	int		move_up;
	long	elem_val;

	move_up = elem_index > op->stack_b->length / 2;
	elem_val = op->b_at(op, elem_index);
	while (op->b_at(op, -1) != elem_val)
	{
		if (move_up)
			op->rb(op);
		else
			op->rrb(op);
	}
}

void	move_a_elem_to_bottom(t_stacks_op *op, size_t elem_index)
{
	int		move_up;
	long	elem_val;

	move_up = elem_index < op->stack_a->length / 2;
	elem_val = op->a_at(op, elem_index);
	while (op->a_at(op, 0) != elem_val)
	{
		if (move_up)
			op->ra(op);
		else
			op->rra(op);
	}
}

int	is_stack_ordered(t_list *stack)
{
	t_iterator	*i;
	int			is_ordered;

	i = stack->get_iterator(stack);
	is_ordered = TRUE;
	while (i->next(i))
	{
		if (i->curr->next && *i->curr->data->as_long < *i->curr->next->data
			->as_long)
		{
			is_ordered = FALSE;
			break ;
		}
	}
	i->free(i);
	return (is_ordered);
}

void	move_stack_b_to_stack_a(t_stacks_op *op)
{
	while (op->stack_b->length > 0)
	{
		op->pa(op);
	}
}
