#include "ft_long.h"
#include "ft_char.h"
#include "ft_boolean.h"
#include "ft_list.h"
#include "libft/libft.h"
#include "math/ft_math.h"

char *ft_nbr_to_str (long long ll)
{
	t_list *list = new_list();
	int is_neg = ll < 0;
	ll = ft_math_abs(ll);
	while (TRUE)
	{
		list->push_str(list, ft_char_to_str(ll % 10 + '0'));
		ll /= 10;
		if (!ll) break;
	}
	if (is_neg)
		list->push_str(list, "-");
	list->reverse(list);
	char *str = list->join(list, "");
	list->free(list);
	return str;
}