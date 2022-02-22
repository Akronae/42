/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include <stdlib.h>

t_link	*new_link(void)
{
	t_link	*link;

	link = malloc(sizeof(t_link));
	link->data = NULL;
	link->data_type = T_TYPE_NULL;
	link->next = NULL;
	link->prev = NULL;
	link->free = &ft_link_free;
	link->get_first = &ft_link_get_first;
	link->get_last = &ft_link_get_last;
	link->insert = &ft_link_insert;
	link->reverse = &ft_link_reverse;
	return (link);
}
