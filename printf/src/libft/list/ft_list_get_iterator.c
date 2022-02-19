#include "ft_list.h"

t_iterator *ft_list_get_iterator(t_list *self)
{
	return new_iterator(self->first_element);
}