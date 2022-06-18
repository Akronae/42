/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_ptr_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_typed_ptr.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include "../map/ft_map.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_typed_ptr_free(t_typed_ptr *self)
{
	if (self->value)
	{
		if (self->type == T_TYPE_LIST)
			((t_list *)self->value)->free(self->value);
		if (self->type == T_TYPE_KEY_VALUE_PAIR)
			((t_key_value_pair *)self->value)->free(self->value);
		if (self->type == T_TYPE_MAP)
			((t_map *)self->value)->free(self->value);
		else
			ft_safe_free(self->value);
	}
	ft_safe_free(self);
}
