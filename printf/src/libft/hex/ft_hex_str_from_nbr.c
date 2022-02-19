#include "../list/ft_list.h"
#include "../iterator/ft_iterator.h"
#include "../char/ft_char.h"
#include "../boolean/ft_boolean.h"

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