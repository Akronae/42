#include "ft_list.h"

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