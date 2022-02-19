#include "ft_char.h"
#include "../libft.h"
#include "../memory/ft_memory.h"

char *ft_char_to_str(char c)
{
	char *str;

	str = ft_calloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
