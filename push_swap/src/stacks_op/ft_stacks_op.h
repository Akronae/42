/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACKS_OP_H
# define FT_STACKS_OP_H

# include "unistd.h"
# include "../libft/list/ft_list.h"

typedef enum e_stack_operation
{
	PA,
	PB,
	PP,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	SA,
	SB,
	SS,
} e_stack_operation;

typedef struct t_stacks_op
{
	struct t_list       *operations;
	struct t_list       *stack_a;
	struct t_list       *stack_b;
    void		        (*free)(struct t_stacks_op *self);
	struct t_stacks_op		*(*pa)(struct t_stacks_op *self);
	struct t_stacks_op		*(*pb)(struct t_stacks_op *self);
	struct t_stacks_op		*(*rra)(struct t_stacks_op *self);
	struct t_stacks_op		*(*rrb)(struct t_stacks_op *self);
	struct t_stacks_op		*(*ra)(struct t_stacks_op *self);
	struct t_stacks_op		*(*rb)(struct t_stacks_op *self);
	struct t_stacks_op		*(*sa)(struct t_stacks_op *self);
	struct t_stacks_op		*(*sb)(struct t_stacks_op *self);
}	t_stacks_op;

void			ft_stacks_op_free(t_stacks_op *self);
t_stacks_op *ft_stacks_op_pa(t_stacks_op *self);
t_stacks_op *ft_stacks_op_pb(t_stacks_op *self);
t_list   	*ft_stack_reverse_rotate(t_list *self);
t_stacks_op *ft_stacks_op_rra(t_stacks_op *self);
t_stacks_op *ft_stacks_op_rrb(t_stacks_op *self);
t_stacks_op *ft_stacks_op_ra(t_stacks_op *self);
t_stacks_op *ft_stacks_op_rb(t_stacks_op *self);
t_stacks_op *ft_stacks_op_sa(t_stacks_op *self);
t_stacks_op *ft_stacks_op_sb(t_stacks_op *self);
t_stacks_op		*new_stacks_op(void);

#endif
