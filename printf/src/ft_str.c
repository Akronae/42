#include "libft/libft.h"

void ft_str_append(char *dst, char *src)
{
	size_t dst_i = ft_strlen(dst);
	size_t src_i = 0;
	while (src[src_i])
	{
		dst[dst_i] = src[src_i];
		dst_i++;
		src_i++;
	}
	dst[dst_i] = '\0';
}