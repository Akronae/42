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
#include <stdlib.h>

t_link	*new_link(void)
{
	t_link	*link;

	link = malloc(sizeof(t_link));
	if (!link)
		return (NULL);
	link->data = NULL;
	link->data_type = T_TYPE_UNKNOWN;
	link->next = NULL;
	link->prev = NULL;
	link->free = &ft_link_free;
	link->get_first = &ft_link_get_first;
	link->get_last = &ft_link_get_last;
	link->insert = &ft_link_insert;
	link->reverse = &ft_link_reverse;
	link->for_each = &ft_link_for_each;
	return (link);
}
