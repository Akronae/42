/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_kv_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_kv_pair.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

t_kv_pair	*new_kv_pair(t_typed_ptr *key, t_typed_ptr *value)
{
	t_kv_pair	*pair;

	pair = ft_safe_malloc(sizeof(t_kv_pair));
	pair->key = key;
	pair->value = value;
	pair->free = ft_kv_pair_free;
	return (pair);
}
