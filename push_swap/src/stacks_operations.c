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

	move_up = elem_index < op->stack_b->length / 2;
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

long	get_greatest_lower_than(long lower_than, t_list *numbers)
{
	t_iterator	*i;
	long long	greatest;

	if (numbers->length == 0)
		return (LONG_MAX);
	i = numbers->get_iterator(numbers);
	greatest = *numbers->find_min(numbers, T_TYPE_LONG)->data->as_long;
	while (i->next(i))
	{
		if (*i->curr->data->as_long > greatest
			&& *i->curr->data->as_long < lower_than)
			greatest = *i->curr->data->as_long;
	}
	i->free(i);
	return (greatest);
}

void	lol(t_stacks_op *op, t_list *biggest)
{
	t_typed_ptr	*typed_ptr;
	t_link		*big;
	long long	greatest;
	long 		index;

	while (biggest->length > 0)
	{
		big = biggest->find(biggest, op->stack_a->get_elem(op->stack_a, -1)->data);
		if (big)
		{
			greatest = get_greatest_lower_than(*big->data->as_long,
					op->stack_b);
			typed_ptr = new_typed_ptr_decimal(greatest);
			index = op->stack_b->find_index(op->stack_b, typed_ptr);
			typed_ptr->free(typed_ptr);
			if (index != INDEX_NOT_FOUND)
				move_b_elem_to_top(op, index);
			if (greatest > *big->data->as_long && op->stack_b->length > 1)
				op->rb(op);
			op->pb(op);
			biggest->free_by_data(biggest, big->data);
		}
		else
			op->ra(op);
	}
}

void	move_biggest_range_to_b(t_stacks_op *op, long from, long to)
{
	t_list		*biggest;
	t_typed_ptr	*typed_ptr;
	t_list		*sorted;
	t_list		*d;

	sorted = op->stack_a->sort(op->stack_a, T_TYPE_LONG);
	d = sorted->reverse(sorted);
	biggest = d->sub(d, from, to);
	lol(op, biggest);
	typed_ptr = new_typed_ptr_decimal(*op->stack_b
			->find_max(op->stack_b, T_TYPE_LONG)->data->as_long);
	move_b_elem_to_top(op, op->stack_b->find_index(op->stack_b, typed_ptr));
	typed_ptr->free(typed_ptr);
	biggest->free(biggest);
	d->free(d);
}
