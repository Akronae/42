/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

t_link	*new_link(void)
{
	t_link	*link;

	link = ft_safe_malloc(sizeof(t_link));
	link->data = NULL;
	link->as_long = NULL;
	link->as_str = NULL;
	link->data_type = T_TYPE_UNKNOWN;
	link->next = NULL;
	link->prev = NULL;
	link->clone = &ft_link_clone;
	link->free = &ft_link_free;
	link->get_first = &ft_link_get_first;
	link->get_last = &ft_link_get_last;
	link->insert = &ft_link_insert;
	link->remove = &ft_link_remove;
	link->set_data = &ft_link_set_data;
	link->reverse = &ft_link_reverse;
	link->for_each = &ft_link_for_each;
	return (link);
}
