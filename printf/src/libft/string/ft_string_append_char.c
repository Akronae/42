#include "ft_string.h"
#include <stdlib.h>
#include "../libft.h"

void ft_string_append_char(char *dst, char src)
{
	size_t dst_i = ft_strlen(dst);
	dst[dst_i] = src;
	dst[dst_i + 1] = '\0';
}