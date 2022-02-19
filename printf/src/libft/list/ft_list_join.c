#include "ft_list.h"
#include "../libft.h"
#include "../string/ft_string.h"

char *ft_list_join(t_list *self, char *delimiter)
{
	size_t total_length = 1;
	t_iterator *iterator = self->get_iterator(self);
	while (iterator->current)
	{
		total_length += ft_strlen(iterator->next_str(iterator)) + ft_strlen(delimiter);
	}
	total_length -= ft_strlen(delimiter);
	char *str = ft_calloc(total_length, sizeof (char));
	iterator->reset(iterator);
	while (iterator->current)
	{
		ft_string_append(str, iterator->next_str(iterator));
		ft_string_append(str, delimiter);
	}
	iterator->free(iterator);
	return str;
}