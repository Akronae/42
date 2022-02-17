/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/17 13:51:30 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include <stdlib.h>
#include <stdio.h>

t_link *ft_link_get_first(t_link *self)
{
	t_link *elem = self;
	while (elem->prev)
		elem = elem->prev;
	return elem;
}

t_link *ft_link_get_last(t_link *self)
{
	t_link *elem = self;
	while (elem->next)
		elem = elem->next;
	return elem;
}

void ft_link_free(t_link *self)
{
	t_link *temp;
	t_link *elem = self->get_first(self);
	while (elem)
	{
		temp = elem;
		elem = elem->next;
		free(temp->data);
		free(temp);
	}
}

t_link *ft_link_insert(t_link *self)
{
	t_link *new_elem = new_link();
	new_elem->prev = self;
	if (self->next)
	{
		new_elem->next = self->next;
		self->next->prev = new_elem;
	}
	self->next = new_elem;
	return new_elem;
}

t_link *ft_link_reverse(t_link *self)
{
	t_link *curr = self->get_last(self);
	t_link *last = NULL;
	while (curr)
	{
		curr->next = curr->prev;
		curr->prev = last;
		last = curr;
		curr = curr->next;
	}
	return self->get_first(self);
}

t_link	*new_link()
{
	t_link *link = malloc(sizeof(t_link));
	link->data = NULL;
	link->next = NULL;
	link->prev = NULL;
	link->free = &ft_link_free;
	link->get_first = &ft_link_get_first;
	link->get_last = &ft_link_get_last;
	link->insert = &ft_link_insert;
	link->reverse = &ft_link_reverse;
	return link;
}