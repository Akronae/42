//
// Created by Alexandre DAUBRICOURT on 7/1/21.
//
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = -1;
	while (str[++i] != '\0')
	{
		c = str[i];
		if (c != '\0')
		{
			ft_putchar(str[i]);
		}
	}
}
