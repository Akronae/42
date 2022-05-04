/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_op_free.c                                :+:      :+:    :+:   */
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

void ft_stacks_op_free(t_stacks_op *self)
{
	self->stack_a->free(self->stack_a);
	self->stack_b->free(self->stack_b);
    ft_safe_free(self);
}
