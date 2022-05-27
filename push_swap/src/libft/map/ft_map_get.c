/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../memory/ft_memory.h"
#include "../string/ft_string.h"
#include "../io/ft_io.h"
#include "../logic/ft_logic.h"
#include <stdlib.h>

t_typed_ptr *ft_map_get(t_map *self, t_typed_ptr *key)
{
	t_iterator			*i;
	t_key_value_pair	*pair;
	void 				*value;
	int					match;

	match = FALSE;
	value = NULL;
	i = self->entries->get_iterator(self->entries);
	while (i->next(i))
	{
		pair = i->curr->data->value;
		if (pair->key->type == key->type)
		{
			if (key->type == T_TYPE_STRING)
				match = ft_str_equal(pair->key->value, key->value);
			else if (key->type == T_TYPE_LONG)
				match = *pair->key->as_long == *key->as_long;
			else
				return ft_exit_err("ft_map_get: cannot handle key of type '%d'.", key->type);

			if (match)
			{
				value = pair->value;
				break;
			}
		}
	}
	i->free(i);
	return (value);
}
