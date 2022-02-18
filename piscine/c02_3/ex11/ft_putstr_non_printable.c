//
// Created by Alexandre DAUBRICOURT on 7/3/21.
//
#include <unistd.h>

int	char_is_printable(char c)
{
	if (c < ' ' || c > '~')
		return (0);
	return (1);
}

void	print_char_to_hex(unsigned char c)
{
	unsigned char	*hex_numerals;

	hex_numerals = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex_numerals[c / 16], 1);
	write(1, &hex_numerals[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!char_is_printable(str[i]))
			print_char_to_hex(str[i]);
		else
			write(1, &str[i], 1);
	}
}
