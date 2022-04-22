/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->first_element = NULL;
	list->last_element = NULL;
	list->length = 0;
	list->free = &ft_list_free;
	list->on_elem_free = NULL;
	list->push = &ft_list_push;
	list->push_malloc = &ft_list_push_malloc;
	list->push_char = &ft_list_push_char;
	list->push_long = &ft_list_push_long;
	list->push_str = &ft_list_push_str;
	list->get_elem = &ft_list_get_elem;
	list->reverse = &ft_list_reverse;
	list->get_iterator = &ft_list_get_iterator;
	list->join = &ft_list_join;
	list->map = &ft_list_map;
	list->for_each = &ft_list_for_each;
	return (list);
}
