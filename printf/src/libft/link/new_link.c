#include "ft_link.h"
#include <stdlib.h>

t_link	*new_link()
{
	t_link *link = malloc(sizeof(t_link));
	link->data = NULL;
	link->data_type = T_TYPE_NULL;
	link->next = NULL;
	link->prev = NULL;
	link->free = &ft_link_free;
	link->get_first = &ft_link_get_first;
	link->get_last = &ft_link_get_last;
	link->insert = &ft_link_insert;
	link->reverse = &ft_link_reverse;
	return link;
}