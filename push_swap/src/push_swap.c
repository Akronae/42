/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
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
#include "libft/map/ft_map.h"
#include "stacks_op/ft_stacks_op.h"

t_list *ft_stack_from_input(t_list *input)
{
	if (input->length <= 1)
		ft_exit_err("no arguments supplied");

	t_list *stack = new_list();
	input->i->skip(input->i, 1);
	while (input->i->next(input->i))
	{
		if (!ft_str_is_numeric(input->i->curr->as_str))
			ft_exit_err("element %d is not a number (%s)", input->i->index, input->i->curr->as_str);
		long nbr = ft_str_to_number(input->i->curr->as_str);
		if (nbr < INT_MIN || nbr > INT_MAX)
			ft_exit_err("element %d is out of [INT_MIN, INT_MAX] boundaries (%s)", input->i->index, input->i->curr->as_str);
		stack->push_long(stack, nbr);
	}
	return (stack);
}

t_stacks_op *ft_stack_sort_len_2 (t_stacks_op *op)
{
	if (op->a_at(op, 0) > op->a_at(op, 1))
		op->sa(op);
	return (op);
}

t_stacks_op *ft_stack_sort_len_3 (t_stacks_op *op)
{
	if (op->a_at(op, -1) == op->max_a)
		op->ra(op);
	if (op->a_at(op, -2) == op->max_a)
		op->rra(op);
	if (op->a_at(op, -1) > op->a_at(op, -2))
		op->sa(op);
	return (op);
}

t_stacks_op *ft_stack_sort_len_5 (t_stacks_op *op)
{
	while (op->stack_b->length < 2)
	{
		if (op->a_at(op, -1) == op->min || op->a_at(op, -1) == op->max)
			op->pb(op);
		else
			op->ra(op);
	}
	ft_stack_sort_len_3(op);
	op->pa(op);
	op->pa(op);
	if (op->a_at(op, -1) != op->max)
		op->sa(op);
	op->ra(op);
	return (op);
}

void move_a_elem_to_top (t_stacks_op *op, size_t elem_index)
{
	int move_up = elem_index > op->stack_a->length / 2;
	long elem_val = op->a_at(op, elem_index);

	while (op->a_at(op, -1) != elem_val)
	{
		if (move_up)
			op->ra(op);
		else
			op->rra(op);
	}
}
void move_b_elem_to_top (t_stacks_op *op, size_t elem_index)
{
	int move_up = elem_index > op->stack_b->length / 2;
	long elem_val = op->b_at(op, elem_index);

	while (op->b_at(op, -1) != elem_val)
	{
		if (move_up)
			op->rb(op);
		else
			op->rrb(op);
	}
}

void move_b_elem_to_bottom (t_stacks_op *op, size_t elem_index)
{
	int move_up = elem_index < op->stack_b->length / 2;
	long elem_val = op->b_at(op, elem_index);

	while (op->b_at(op, 0) != elem_val)
	{
		if (move_up)
			op->rb(op);
		else
			op->rrb(op);
	}
}

void move_elem_to_b (t_stacks_op *op, size_t elem_index)
{
	move_a_elem_to_top(op, elem_index);
	op->pb(op);
}

void move_unordered_to_b(t_stacks_op *op)
{
	t_iterator	*i;

	i = op->stack_a->get_iterator(op->stack_a);
	while (i->next(i))
	{
		if (i->index > 0 && op->a_at(op, i->index - 1) < op->a_at(op, i->index))
		{
			move_elem_to_b(op, i->index);
			i->reset(i);
		}
	}
	i->free(i);
}

void move_stack_b_to_stack_a (t_stacks_op *op)
{
	while (op->stack_b->length > 0)
	{
		op->pa(op);
	}
}

long get_lowest_greater_than(long greater_than, t_list *numbers)
{
	if (numbers->length == 0)
		return (LONG_MIN);

	t_iterator *i = numbers->get_iterator(numbers);
	long long lowest;

	lowest = *numbers->find_max(numbers, T_TYPE_LONG)->as_long;
	while (i->next(i))
	{
		if (*i->curr->as_long < lowest && *i->curr->as_long > greater_than)
			lowest = *i->curr->as_long;
	}
	i->free(i);
	return (lowest);
}

void move_biggest_to_b(t_stacks_op *op, long from, long to)
{
	t_list	*smallest;
	t_link *small;
	t_typed_ptr *typed_ptr;
	t_list	*sorted;
	t_list	*d;

//	smallest = op->stack_a->find_mins(op->stack_a, T_TYPE_LONG, count);
	sorted = op->stack_a->sort(op->stack_a, T_TYPE_LONG);
	d = sorted->reverse(sorted);
	smallest = d->sub(d, from, to);
	while (smallest->length > 0)
	{
		typed_ptr = new_typed_ptr_decimal(op->a_at(op, -1));
		small = smallest->find(smallest, typed_ptr);
		typed_ptr->free(typed_ptr);
		if (small)
		{
			long long lowest = get_lowest_greater_than(*small->as_long, op->stack_b);
			typed_ptr = new_typed_ptr_decimal(lowest);
			long index = op->stack_b->find_index(op->stack_b, typed_ptr);
			typed_ptr->free(typed_ptr);
			if (index != INDEX_NOT_FOUND)
				move_b_elem_to_top(op, index);
			if (lowest < *small->as_long && op->stack_b->length > 1)
			{
				op->rb(op);
			}
			op->pb(op);
			smallest->free_by_data(smallest, small->data);
		}
		else
			op->ra(op);
	}
	typed_ptr = new_typed_ptr_decimal(op->min_b);
	move_b_elem_to_top(op, op->stack_b->find_index(op->stack_b, typed_ptr));
	typed_ptr->free(typed_ptr);
	smallest->free(smallest);
	d->free(d);
}

void move_b_to_a_ordered(t_stacks_op *op)
{
	while (op->stack_b->length > 0)
	{
		move_b_elem_to_top(op, op->stack_b->index_of(op->stack_b, op->stack_b->find_max(op->stack_b, T_TYPE_LONG)));
		op->pa(op);
//		move_a_elem_to_top(op, op->stack_a->index_of(op->stack_a, op->stack_a->find_min(op->stack_a, T_TYPE_LONG)));
//		ft_printfl("== %s{.free()}", op->stack_a->join(op->stack_a, ", "));
//		while (op->a_at(op, -1) < op->b_at(op, -1) && op->a_at(op, -1)!= op->max_a)
//		{
//			op->ra(op);
//		}
//		if (op->a_at(op, -1) == op->max_a)
//			op->ra(op);
//
//		op->pa(op);
//		ft_printfl("=> %s{.free()}", op->stack_a->join(op->stack_a, ", "));
	}
//	move_a_elem_to_top(op, op->stack_a->index_of(op->stack_a, op->stack_a->find_min(op->stack_a, T_TYPE_LONG)));
}

t_stacks_op *ft_stack_sort_len_any (t_stacks_op *op)
{
	long steps = 10;
	size_t i = 0;
	while (i < op->stack_a->length + op->stack_b->length - 1)
	{
		long to = ft_math_min(i + steps - 1, op->stack_a->length);
		move_biggest_to_b(op, i, to);
		move_stack_b_to_stack_a(op);
		i = to + 1;
	}

//	move_biggest_to_b(op, 10, 19);
//	move_stack_b_to_stack_a(op);
//	move_biggest_to_b(op, 20, 29);
//	move_stack_b_to_stack_a(op);
//	move_biggest_to_b(op, 30, 39);
//	move_stack_b_to_stack_a(op);
//	move_biggest_to_b(op, 40, 49);
//	move_stack_b_to_stack_a(op);
//	move_biggest_to_b(op, 50, 59);
//	move_stack_b_to_stack_a(op);
//	move_biggest_to_b(op, 60, 69);
//	move_stack_b_to_stack_a(op);
//	move_biggest_to_b(op, 70, 79);
//	move_stack_b_to_stack_a(op);
//	move_biggest_to_b(op, 80, 89);
//	move_stack_b_to_stack_a(op);
//	move_biggest_to_b(op, 90, 99);
//	move_stack_b_to_stack_a(op);

	return (op);
}

t_stacks_op *ft_sort_stack(t_list *stack)
{
	t_stacks_op *op = new_stacks_op();
	op->set_stack_a(op, stack);

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

char *ft_commands_to_str(t_list *commands)
{
	t_list	*to_str = new_list();
	t_iterator *i = commands->get_iterator(commands);
	char		*str;
	t_map	*map = new_map();

	map->add(map, ft_d(SA), ft_s("sa"));
	map->add(map, ft_d(SB), ft_s("sb"));
	map->add(map, ft_d(SS), ft_s("ss"));
	map->add(map, ft_d(PA), ft_s("pa"));
	map->add(map, ft_d(PB), ft_s("pb"));
	map->add(map, ft_d(PP), ft_s("pp"));
	map->add(map, ft_d(RA), ft_s("ra"));
	map->add(map, ft_d(RB), ft_s("rb"));
	map->add(map, ft_d(RR), ft_s("rr"));
	map->add(map, ft_d(RRA), ft_s("rra"));
	map->add(map, ft_d(RRB), ft_s("rrb"));
	map->add(map, ft_d(RRR), ft_s("rrr"));
	while (i->next(i))
		to_str->push_str(to_str, ft_strdup(map->get(map, ft_d(*i->curr->as_long))->value));
	i->free(i);
	str = to_str->join(to_str, "\n");
	to_str->free(to_str);
	map->free(map);
	return (str);
}

int main (int argc, char **argv)
{
	t_list *input = new_list();
	input->from_str_arr(input, argv, 0, argc);
	t_stacks_op *op = ft_sort_stack(ft_stack_from_input(input));
	t_list *stack_a_rev = op->stack_a->reverse(op->stack_a);
	t_list *stack_b_rev = op->stack_b->reverse(op->stack_b);
	ft_printfl("%s{.free()}\n-----------\nstack_a\n", stack_a_rev->join(stack_a_rev, "\n"));
	ft_printfl("%s{.free()}\n-----------\nstack_b\n", stack_b_rev->join(stack_b_rev, "\n"));
	ft_printfl("commands\n-----------\n(%d)", op->operations->length);
	//ft_printfl("commands\n-----------\n%s{.free()} (%d)", ft_commands_to_str(op->operations), op->operations->length);
	if (op->stack_b->length > 0)
		ft_printfl("stack b is not empty!!!!");
	op->free(op);

	input->free(input);
}