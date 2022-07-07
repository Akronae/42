/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_typed_ptr	*ft_map_get_lld(t_map *self, t_llong key_lld)
{
	t_typed_ptr	*key;
	t_typed_ptr	*value;

	key = ft_lld(key_lld);
	value = self->get(self, key);
	key->free(key);
	return (value);
}
