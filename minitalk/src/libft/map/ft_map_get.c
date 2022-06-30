/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
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

t_typed_ptr	*ft_map_get(t_map *self, t_typed_ptr *key)
{
	t_iterator			*i;
	t_key_value_pair	*curr_pair;
	void				*value;

	value = NULL;
	i = self->entries->get_iterator(self->entries);
	while (i->next(i))
	{
		curr_pair = i->curr->data->value;
		if (key->value_equals(key, curr_pair->key))
		{
			value = curr_pair->value;
			break ;
		}
	}
	i->free(i);
	return (value);
}
