#include "ft_list.h"
#include <stdlib.h>

void ft_list_free(t_list *self)
{
	self->first_element->free(self->first_element);
	free(self);
}