/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iterator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/17 14:38:19 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_iterator.h"
#include <stdlib.h>

void *ft_iterator_next(t_iterator *self)
{
	t_link *curr = self->current;
	if (!curr)
		return NULL;
	self->current = self->current->next;
	return curr->data;
}

char *ft_iterator_next_str (t_iterator *self)
{
	return (char *) self->next(self);
}

void ft_iterator_reset(t_iterator *self)
{
	self->current = self->first;
}

void ft_iterator_free(t_iterator *self)
{
	free(self);
}

t_iterator 	*new_iterator(t_link *link)
{
	t_iterator *iterator = malloc(sizeof(t_iterator));
	iterator->first = link;
	iterator->current = link;
	iterator->next = &ft_iterator_next;
	iterator->next_str = &ft_iterator_next_str;
	iterator->reset = &ft_iterator_reset;
	iterator->free = &ft_iterator_free;
	return iterator;
}
