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
#include "libft/io/ft_io.h"
#include "libft/list/ft_list.h"
#include "libft/string/ft_string.h"
#include "libft/number/ft_number.h"
#include "libft/memory/ft_memory.h"
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
	op->sa(op);
	return (op);
}

t_stacks_op *ft_sort_stack(t_list *stack)
{
	t_stacks_op *op = new_stacks_op();
	op->stack_a->free(op->stack_a);
	op->stack_a = stack;
	if (op->stack_a->length <= 2)
		ft_stack_sort_len_2(op);
	return (op);
}

int main (int argc, char **argv)
{
	t_list *input = new_list();
	input->from_str_arr(input, argv, 0, argc);
	t_stacks_op *op = ft_sort_stack(input);
	ft_printfl("stack_a\n-----------\n%s{.free()}", op->stack_a->join(op->stack_a, "\n"));
	ft_printfl("commands\n-----------\n%s{.free()} (%d)", op->operations->join(op->operations, ", "), op->operations->length);

	op->free(op);
}