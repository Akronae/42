/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "../libft/memory/ft_memory.h"
#include <stdlib.h>

t_stack *new_stack(void)
{
	t_stack *stack;

	stack = ft_safe_malloc(sizeof(t_list));
    stack->base = new_list();
    stack->free = &ft_stack_free;
    stack->push = &ft_stack_push;
    stack->reverse_rotate = &ft_stack_reverse_rotate;
    stack->rotate = &ft_stack_rotate;
	return (stack);
}
