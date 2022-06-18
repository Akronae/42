/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_ptr_to_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_typed_ptr.h"
#include "../string/ft_string.h"
#include "../number/ft_number.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include "../char/ft_char.h"
#include "../map/ft_map.h"

t_string	ft_key_value_pair_to_str(t_key_value_pair *pair)
{
	return (ft_str_format("{%s{.free()}: %s{.free()}}", pair->key->to_str(pair->key), pair->value->to_str(pair->value)));
}

t_string	ft_list_to_str(t_list *list)
{
	return (ft_str_format("[%s{.free()}]", list->join(list, ", ")));
}

t_string 	ft_typed_ptr_to_str(t_typed_ptr *self)
{
	if (self->type == T_TYPE_UNKNOWN)
		return (ft_strdup(T_TYPE_UNKNOWN_STR));
	else if (self->type == T_TYPE_STRING)
		return (ft_strdup(self->as_str));
	else if (self->type == T_TYPE_CHAR)
		return (ft_char_to_str(*self->as_str));
	else if (self->type == T_TYPE_LLONG)
		return (ft_number_to_str(*self->as_llong));
	else if (self->type == T_TYPE_KEY_VALUE_PAIR)
		return (ft_key_value_pair_to_str(self->value));
	else if (self->type == T_TYPE_LIST)
		return (ft_list_to_str(self->value));
	else if (self->type == T_TYPE_MAP)
		return (ft_list_to_str(((t_map *)self->value)->entries));
	else
		return (ft_exit_err("ft_typed_ptr_to_str: cannot parse type %d",
					self->type));
}
