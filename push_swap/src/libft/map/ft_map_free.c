/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

void ft_map_free_entry(t_link *entry)
{
	t_key_value_pair	*pair;

	pair = entry->data;
	pair->free(pair);
	entry->data = NULL;
	entry->typed_ptr->value = NULL;
}

void ft_map_free(t_map *self)
{
	self->entries->on_elem_free = ft_map_free_entry;
	self->entries->free(self->entries);
	ft_safe_free(self);
}
