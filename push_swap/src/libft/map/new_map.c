/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
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

t_map	*new_map(void)
{
	t_map	*map;

	map = ft_safe_malloc(sizeof(t_map));
	map->entries = new_list();
	map->add = ft_map_add;
	map->free = ft_map_free;
	map->get = ft_map_get;
	return (map);
}
