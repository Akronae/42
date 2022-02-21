#include "ft_list.h"

void ft_list_push_char(t_list *self, char c)
{
	self->push_malloc(self, sizeof(int));
	*((char *)self->last_element->data) = c;
	self->last_element->data_type = T_TYPE_CHAR;
}