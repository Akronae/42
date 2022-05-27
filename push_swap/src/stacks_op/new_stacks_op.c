/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stacks_op.c                                        :+:      :+:    :+:   */
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

t_stacks_op *new_stacks_op(void)
{
	t_stacks_op *stack_op;

	stack_op = ft_safe_malloc(sizeof(t_stacks_op));
	stack_op->operations = new_list();
	stack_op->stack_a = new_list();
	stack_op->stack_b = new_list();
	stack_op->get_min = &ft_stacks_op_get_min;
	stack_op->get_max = &ft_stacks_op_get_max;
	stack_op->a_at = &ft_stacks_op_a_at;
	stack_op->b_at = &ft_stacks_op_b_at;
	stack_op->free = &ft_stacks_op_free;
	stack_op->compute_stats = &ft_stacks_op_compute_stats;
	stack_op->set_stack_a = &ft_stacks_op_set_stack_a;
	stack_op->set_stack_b = &ft_stacks_op_set_stack_b;
	stack_op->sa = &ft_stacks_op_sa;
	stack_op->sb = &ft_stacks_op_sb;
	stack_op->ra = &ft_stacks_op_ra;
	stack_op->rb = &ft_stacks_op_rb;
	stack_op->rra = &ft_stacks_op_rra;
	stack_op->rrb = &ft_stacks_op_rrb;
	stack_op->pa = &ft_stacks_op_pa;
	stack_op->pb = &ft_stacks_op_pb;
	stack_op->compute_stats(stack_op);
	return (stack_op);
}
