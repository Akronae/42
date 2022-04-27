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
#include "../memory/ft_memory.h"
#include <stdlib.h>

t_list	*new_list(void)
{
	t_list	*list;

	list = ft_safe_malloc(sizeof(t_list));
	list->first = NULL;
	list->last = NULL;
	list->i = new_iterator(list);
	list->length = 0;
	list->free = &ft_list_free;
	list->from_str_arr = &ft_list_from_str_arr;
	list->on_elem_free = NULL;
	list->push = &ft_list_push;
	list->push_char = &ft_list_push_char;
	list->push_data = &ft_list_push_data;
	list->push_long = &ft_list_push_long;
	list->push_str = &ft_list_push_str;
	list->remove_at = &ft_list_remove_at;
	list->get_elem = &ft_list_get_elem;
	list->reverse = &ft_list_reverse;
	list->swap = &ft_list_swap;
	list->get_iterator = &ft_list_get_iterator;
	list->insert_at = &ft_list_insert_at;
	list->join = &ft_list_join;
	list->map = &ft_list_map;
	list->for_each = &ft_list_for_each;
	return (list);
}
