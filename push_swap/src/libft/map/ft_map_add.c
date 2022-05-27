/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include <stdlib.h>

t_key_value_pair	*ft_map_add(t_map *self, t_typed_ptr *key,
					t_typed_ptr *value)
{
	if (self->get(self, key))
		return (ft_exit_err("ft_map_add: "
				"key '%s' already exists in the map.", key->value));
	self->entries->push_data(self->entries,
		new_typed_ptr(T_TYPE_UNKNOWN, new_key_value_pair(key, value)));
	return (self->entries->last->data->value);
}
