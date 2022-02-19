#include "ft_string.h"
#include <stdlib.h>
#include "../char/ft_char.h"

void ft_string_to_upper(char *str)
{
	size_t i = 0;
	while (str[i])
	{
		str[i] = ft_char_to_upper(str[i]);
		i += 1;
	}
}