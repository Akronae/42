#include "ft_iterator.h"
#include <stdlib.h>

void ft_iterator_free(t_iterator *self)
{
	free(self);
}