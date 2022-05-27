/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_op_compute_stats.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks_op.h"
#include "../libft/memory/ft_memory.h"
#include "../libft/math/ft_math.h"
#include "../libft/logic/ft_logic.h"
#include <stdlib.h>

t_stacks_op	*ft_stacks_op_compute_stats(t_stacks_op *self)
{
	self->stacks_length = self->stack_a->length + self->stack_b->length;
	return (self);
}
