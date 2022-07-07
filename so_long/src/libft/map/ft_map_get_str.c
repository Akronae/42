/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get_str.c                                   :+:      :+:    :+:   */
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

t_typed_ptr	*ft_map_get_str(t_map *self, t_str key_str)
{
	t_typed_ptr	*key;
	t_typed_ptr	*value;

	key = ft_s(key_str);
	value = self->get(self, key);
	key->free(key);
	return (value);
}
