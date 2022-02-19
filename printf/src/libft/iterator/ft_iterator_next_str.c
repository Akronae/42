#include "ft_iterator.h"

char *ft_iterator_next_str (t_iterator *self)
{
	return (char *) self->next(self);
}