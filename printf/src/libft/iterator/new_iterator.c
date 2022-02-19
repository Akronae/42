#include "ft_iterator.h"
#include <stdlib.h>

t_iterator 	*new_iterator(t_link *link)
{
	t_iterator *iterator = malloc(sizeof(t_iterator));
	iterator->first = link;
	iterator->current = link;
	iterator->next = &ft_iterator_next;
	iterator->next_str = &ft_iterator_next_str;
	iterator->reset = &ft_iterator_reset;
	iterator->free = &ft_iterator_free;
	return iterator;
}