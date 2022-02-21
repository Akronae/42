#include "ft_list.h"
#include "../libft.h"
#include "../string/ft_string.h"
#include "../memory//ft_memory.h"

char *ft_list_join(t_list *self, char *delimiter)
{
	size_t total_length = 1;
	t_iterator *iterator = self->get_iterator(self);
	while (iterator->current)
	{
		if (iterator->current->data_type == T_TYPE_STRING)
			total_length += ft_strlen(iterator->current->data);
		else if (iterator->current->data_type == T_TYPE_CHAR)
			total_length += 1;
		total_length += ft_strlen(delimiter);
		iterator->next(iterator);
	}
	total_length -= ft_strlen(delimiter);
	char *str = ft_calloc(sizeof (char) * total_length);
	iterator->reset(iterator);
	while (iterator->current)
	{
		if (iterator->current->data_type == T_TYPE_STRING)
			ft_string_append(str, iterator->next_str(iterator));
		else if (iterator->current->data_type == T_TYPE_CHAR)
			ft_string_append_char(str, iterator->next_char(iterator));
		ft_string_append(str, delimiter);
	}
	iterator->free(iterator);
	return str;
}