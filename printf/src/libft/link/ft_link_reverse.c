#include "ft_link.h"
#include "stdlib.h"

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