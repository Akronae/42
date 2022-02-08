//
// Created by alexr on 7/11/2021.
//

// If we're compiling for Windows, unistd.h isn't available.
# include <unistd.h>
#include "io_utils.h"
#include "string_utils.h"
#include "constants.h"

void	putstr(char *str)
{
	write(1, str, str_len(str));
}

void	putnbr(int nbr)
{
	if (nbr < 0)
	{
		io_putchar('-');
		putnbr(-nbr);
		return ;
	}
	if (nbr > 9)
	{
		putnbr(nbr / 10);
	}
	io_putchar(nbr % 10 + '0');
}

void	io_putchar(char c)
{
	write(1, &c, 1);
}

void	nl(void)
{
	io_putchar('\n');
}

void	putarraystr(char **arr)
{
	int	i;

	putstr("[");
	i = -1;
	while (*arr[++i] != UNDEFINED)
	{
		putstr(arr[i]);
		if (*arr[i + 1] != UNDEFINED)
			putstr(", ");
	}
	putstr("]");
}
