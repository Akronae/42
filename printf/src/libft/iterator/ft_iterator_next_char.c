#include "ft_iterator.h"

char ft_iterator_next_char (t_iterator *self)
{
	return *((char *)self->next(self));
}