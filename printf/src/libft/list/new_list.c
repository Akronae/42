/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->first_element = NULL;
	list->last_element = NULL;
	list->length = 0;
	list->free = &ft_list_free;
	list->push = &ft_list_push;
	list->push_malloc = &ft_list_push_malloc;
	list->push_char = &ft_list_push_char;
	list->push_str = &ft_list_push_str;
	list->reverse = &ft_list_reverse;
	list->get_iterator = &ft_list_get_iterator;
	list->join = &ft_list_join;
	return (list);
}
