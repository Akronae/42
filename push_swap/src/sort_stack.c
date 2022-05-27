/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
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
#include "stacks_operations.h"

t_stacks_op *ft_stack_sort_len_2 (t_stacks_op *op)
{
	if (op->a_at(op, 0) < op->a_at(op, 1))
		op->sa(op);
	return (op);
}

t_stacks_op *ft_stack_sort_len_3 (t_stacks_op *op)
{
	if (op->a_at(op, -1) == *op->stack_a->find_max(op->stack_a, T_TYPE_LONG)->data->as_long)
		op->ra(op);
	if (op->a_at(op, -2) == *op->stack_a->find_max(op->stack_a, T_TYPE_LONG)->data->as_long)
		op->rra(op);
	if (op->a_at(op, -1) > op->a_at(op, -2))
		op->sa(op);
	return (op);
}

t_stacks_op *ft_stack_sort_len_5 (t_stacks_op *op)
{
	while (op->stack_b->length < 2)
	{
		if (op->a_at(op, -1) == op->get_min(op) || op->a_at(op, -1) == op->get_max(op))
			op->pb(op);
		else
			op->ra(op);
	}
	ft_stack_sort_len_3(op);
	op->pa(op);
	op->pa(op);
	if (op->a_at(op, -1) != op->get_max(op))
		op->sa(op);
	op->ra(op);
	return (op);
}

t_stacks_op *ft_stack_sort_len_any (t_stacks_op *op)
{
	long steps;

	steps = op->stacks_length * 0.26;
	if (op->stacks_length >= 500)
		steps = op->stacks_length * 0.10;
	size_t i = 0;
	while (i < op->stacks_length - 1)
	{
		long to = ft_math_min(i + steps, op->stack_a->length);
		move_biggest_to_b(op, i, to);
		move_stack_b_to_stack_a(op);
		i = to;
	}
	return (op);
}

t_stacks_op *ft_sort_stack(t_list *stack)
{
	t_stacks_op *op = new_stacks_op();

	op->set_stack_a(op, stack);
	if (is_stack_ordered(op->stack_a))
		return (op);
	if (op->stack_a->length <= 1)
		return (op);
	else if (op->stack_a->length <= 2)
		return ft_stack_sort_len_2(op);
	else if (op->stack_a->length <= 3)
		return (ft_stack_sort_len_3(op));
	else if (op->stack_a->length <= 5)
		return (ft_stack_sort_len_5(op));
	else
		return (ft_stack_sort_len_any(op));
}
