/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_OPERATIONS_H
# define STACKS_OPERATIONS_H

void move_b_elem_to_top (t_stacks_op *op, size_t elem_index);
void move_a_elem_to_bottom (t_stacks_op *op, size_t elem_index);
int is_stack_ordered(t_list *stack);
void move_stack_b_to_stack_a (t_stacks_op *op);
long get_greatest_lower_than(long lower_than, t_list *numbers);
void move_biggest_to_b(t_stacks_op *op, long from, long to);

#endif