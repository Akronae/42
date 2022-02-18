#include "libft/libft.h"
#include "ft_char.h"

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

void ft_str_to_upper(char *str)
{
	size_t i = 0;
	while (str[i])
	{
		str[i] = ft_char_to_upper(str[i]);
		i += 1;
	}
}