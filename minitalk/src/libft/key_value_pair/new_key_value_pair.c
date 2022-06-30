/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_key_value_pair.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_value_pair.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

t_key_value_pair	*new_key_value_pair(t_typed_ptr *key, t_typed_ptr *value)
{
	t_key_value_pair	*pair;

	pair = ft_safe_malloc(sizeof(t_key_value_pair));
	pair->key = key;
	pair->value = value;
	pair->free = ft_key_value_pair_free;
	return (pair);
}
