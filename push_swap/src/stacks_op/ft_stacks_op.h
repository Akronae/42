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
}	t_stack_operation;

typedef struct t_stacks_op
{
	struct t_list		*operations;
	struct t_list		*stack_a;
	struct t_list		*stack_b;
	size_t				stacks_length;
	long long			(*get_min)(struct t_stacks_op *self);
	long long			(*get_max)(struct t_stacks_op *self);
	long				(*a_at)(struct t_stacks_op *self, long index);
	long				(*b_at)(struct t_stacks_op *self, long index);
	struct t_stacks_op	*(*compute_stats)(struct t_stacks_op *self);
	void				(*free)(struct t_stacks_op *self);
	struct t_stacks_op	*(*set_stack_a)(struct t_stacks_op *self,
			t_list *new_stack);
	struct t_stacks_op	*(*set_stack_b)(struct t_stacks_op *self,
			t_list *new_stack);
	struct t_stacks_op	*(*pa)(struct t_stacks_op *self);
	struct t_stacks_op	*(*pb)(struct t_stacks_op *self);
	struct t_stacks_op	*(*rra)(struct t_stacks_op *self);
	struct t_stacks_op	*(*rrb)(struct t_stacks_op *self);
	struct t_stacks_op	*(*ra)(struct t_stacks_op *self);
	struct t_stacks_op	*(*rb)(struct t_stacks_op *self);
	struct t_stacks_op	*(*sa)(struct t_stacks_op *self);
	struct t_stacks_op	*(*sb)(struct t_stacks_op *self);
}	t_stacks_op;

long		ft_stacks_op_a_at(t_stacks_op *self, long index);
long		ft_stacks_op_b_at(t_stacks_op *self, long index);
void		ft_stacks_op_free(t_stacks_op *self);
long long	ft_stacks_op_get_min(t_stacks_op *self);
long long	ft_stacks_op_get_max(t_stacks_op *self);
t_stacks_op	*ft_stacks_op_set_stack_a(t_stacks_op *self, t_list *new_stack);
t_stacks_op	*ft_stacks_op_set_stack_b(t_stacks_op *self, t_list *new_stack);
t_stacks_op	*ft_stacks_op_pa(t_stacks_op *self);
t_stacks_op	*ft_stacks_op_pb(t_stacks_op *self);
t_list		*ft_stack_reverse_rotate(t_list *self);
t_stacks_op	*ft_stacks_op_rra(t_stacks_op *self);
t_stacks_op	*ft_stacks_op_rrb(t_stacks_op *self);
t_stacks_op	*ft_stacks_op_ra(t_stacks_op *self);
t_stacks_op	*ft_stacks_op_rb(t_stacks_op *self);
t_stacks_op	*ft_stacks_op_sa(t_stacks_op *self);
t_stacks_op	*ft_stacks_op_sb(t_stacks_op *self);
t_stacks_op	*ft_stacks_op_compute_stats(t_stacks_op *self);
t_stacks_op	*new_stacks_op(void);

#endif
