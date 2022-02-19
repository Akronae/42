#include "ft_list.h"
#include <stdlib.h>

void ft_list_push_malloc(t_list *self, int malloc_size)
{
	self->push(self);
	self->last_element->data = malloc(malloc_size);
}