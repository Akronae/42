#include "ft_char.h"
#include "../libft.h"

char *ft_char_to_str(char c)
{
	char *str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
