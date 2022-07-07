/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_ptr_set_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_typed_ptr.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

void	ft_typed_ptr_set_value(t_typed_ptr *self, void *value)
{
	self->value = value;
	self->as_long = (long *) value;
	self->as_llong = (t_llong *) value;
	self->as_str = (t_str) value;
}
