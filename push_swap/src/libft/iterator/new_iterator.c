/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_iterator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_iterator.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

t_iterator	*new_iterator(t_list *list)
{
	t_iterator	*iterator;

	iterator = ft_safe_malloc(sizeof(t_iterator));
	iterator->list = list;
	iterator->curr = NULL;
	iterator->index = 0;
	iterator->next = &ft_iterator_next;
	iterator->next_str = &ft_iterator_next_str;
	iterator->next_char = &ft_iterator_next_char;
	iterator->next_long = &ft_iterator_next_long;
	iterator->reset = &ft_iterator_reset;
	iterator->skip = &ft_iterator_skip;
	iterator->free = &ft_iterator_free;
	return (iterator);
}
