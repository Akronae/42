#include "ft_link.h"
#include <stdlib.h>

void ft_link_free(t_link *self)
{
	t_link *temp;
	t_link *elem = self->get_first(self);
	while (elem)
	{
		temp = elem;
		elem = elem->next;
		free(temp->data);
		free(temp);
	}
}