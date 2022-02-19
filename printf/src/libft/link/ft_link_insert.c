#include "ft_link.h"

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