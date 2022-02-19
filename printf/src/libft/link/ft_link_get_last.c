#include "ft_link.h"

t_link *ft_link_get_last(t_link *self)
{
	t_link *elem = self;
	while (elem->next)
		elem = elem->next;
	return elem;
}