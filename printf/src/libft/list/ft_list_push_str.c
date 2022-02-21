#include "ft_list.h"

void ft_list_push_str(t_list *self, char *str)
{
	self->push(self);
	self->last_element->data = str;
	self->last_element->data_type = T_TYPE_STRING;
}