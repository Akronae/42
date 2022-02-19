#include "ft_link.h"

t_link *ft_link_get_first(t_link *self)
{
	t_link *elem = self;
	while (elem->prev)
		elem = elem->prev;
	return elem;
}