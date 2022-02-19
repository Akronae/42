#include "ft_list.h"

void ft_list_reverse(t_list *self)
{
	self->first_element = self->first_element->reverse(self->first_element);
	self->last_element = self->first_element->get_last(self->first_element);
}