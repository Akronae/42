#include "ft_iterator.h"

void ft_iterator_reset(t_iterator *self)
{
	self->current = self->first;
}