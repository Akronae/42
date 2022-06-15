/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_ptr_value_equals.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_typed_ptr.h"
#include "../memory/ft_memory.h"
#include "../string/ft_string.h"
#include "../io/ft_io.h"
#include "../logic/ft_logic.h"
#include "../ptr/ft_ptr.h"
#include <stdlib.h>

int	ft_typed_ptr_value_equals(t_typed_ptr *self, t_typed_ptr *to)
{
	if (self->type != to->type)
		return (false );
	if (self->type == T_TYPE_STRING)
		return (ft_str_equal((t_string ) self->value, (t_string ) to->value));
	if (self->type == T_TYPE_LLONG)
		return (*ft_ptr_cast_ll(self->value) == *ft_ptr_cast_ll(to->value));
	else
		ft_exit_err("ft_typed_ptr_value_equals: "
			"could not compare data type '%d'.", self->type);
	return (false );
}
