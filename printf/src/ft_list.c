#include "ft_list.h"
#include "ft_str.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void ft_list_push(t_list *self)
{
	if (!self->first_element)
	{
		self->first_element = new_link();
		self->last_element = self->first_element;
	}
	else
		self->last_element = self->last_element->insert(self->last_element);
	self->length += 1;
}

void ft_list_push_malloc(t_list *self, int malloc_size)
{
	self->push(self);
	self->last_element->data = malloc(malloc_size);
}

void ft_list_push_char(t_list *self, char c)
{
	self->push_malloc(self, sizeof(int));
	*((char *)self->last_element->data) = c;
}

void ft_list_push_str(t_list *self, char *str)
{
	self->push(self);
	self->last_element->data = str;
}

void ft_list_free(t_list *self)
{
	self->first_element->free(self->first_element);
	free(self);
}

t_iterator *ft_list_get_iterator(t_list *self)
{
	return new_iterator(self->first_element);
}

void ft_list_reverse(t_list *self)
{
	self->first_element = self->first_element->reverse(self->first_element);
	self->last_element = self->first_element->get_last(self->first_element);
}

char *ft_list_join(t_list *self, char *delimiter)
{
	size_t total_length = 1;
	t_iterator *iterator = self->get_iterator(self);
	while (iterator->current)
	{
		total_length += ft_strlen(iterator->next_str(iterator)) + ft_strlen(delimiter);
	}
	total_length -= ft_strlen(delimiter);
	char *str = ft_calloc(total_length, sizeof (char));
	iterator->reset(iterator);
	while (iterator->current)
	{
		ft_str_append(str, iterator->next_str(iterator));
		ft_str_append(str, delimiter);
	}
	iterator->free(iterator);
	return str;
}

t_list	*new_list()
{
	t_list *list = malloc(sizeof(t_list));
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
	return list;
}