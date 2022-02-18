#include "ft_list.h"
#include "ft_link.h"
#include "ft_iterator.h"
#include "ft_boolean.h"
#include "ft_char.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

char *ft_hex_str_from_nbr(unsigned long long ull)
{
	char *base = "0123456789abcdef";
	t_list *list = new_list();
	while (TRUE)
	{
		list->push_str(list, ft_char_to_str(base[ull % 16]));
		ull /= 16;
		if (!ull) break;
	}
	list->reverse(list);
	char *str = list->join(list, "");
	list->free(list);
	return str;
}