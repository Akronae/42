/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_op_get_max.c                             :+:      :+:    :+:   */
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
#include "limits.h"
#include <stdlib.h>

long long ft_stacks_op_get_max(t_stacks_op *self)
{
	if (self->stack_a->length == 0 && self->stack_b->length == 0)
		return (LLONG_MIN);
	if (self->stack_a->length == 0)
		return (*self->stack_b->find_max(self->stack_b, T_TYPE_LONG)->data->as_long);
	if (self->stack_b->length == 0)
		return (*self->stack_a->find_max(self->stack_a, T_TYPE_LONG)->data->as_long);
	return ft_math_max(*self->stack_a->find_max(self->stack_a, T_TYPE_LONG)->data->as_long,
					   *self->stack_b->find_max(self->stack_b, T_TYPE_LONG)->data->as_long);
}
