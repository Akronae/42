/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations_2.c                                :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"
#include "libft/io/ft_io.h"
#include "libft/list/ft_list.h"
#include "stacks_op/ft_stacks_op.h"
#include "stacks_operations.h"

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

void	move_range_to_b(t_stacks_op *op, t_list *range)
{
	t_typed_ptr	*typed_ptr;
	t_link		*e;
	long long	greatest;
	long		index;

	while (range->length > 0)
	{
		e = range->find(range, op->stack_a->get_elem(op->stack_a, -1)->data);
		if (e)
		{
			greatest = get_greatest_lower_than(*e->data->as_long,
					op->stack_b);
			typed_ptr = new_typed_ptr_decimal(greatest);
			index = op->stack_b->find_index(op->stack_b, typed_ptr);
			typed_ptr->free(typed_ptr);
			if (index != INDEX_NOT_FOUND)
				move_b_elem_to_top(op, index);
			if (greatest > *e->data->as_long && op->stack_b->length > 1)
				op->rb(op);
			op->pb(op);
			range->free_by_data(range, e->data);
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
	move_range_to_b(op, biggest);
	typed_ptr = new_typed_ptr_decimal(*op->stack_b
			->find_max(op->stack_b, T_TYPE_LONG)->data->as_long);
	move_b_elem_to_top(op, op->stack_b->find_index(op->stack_b, typed_ptr));
	typed_ptr->free(typed_ptr);
	biggest->free(biggest);
	d->free(d);
}
