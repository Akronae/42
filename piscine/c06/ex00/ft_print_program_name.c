//
// Created by Alexandre DAUBRICOURT on 7/9/21.
//
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		ft_putchar(str[i]);
	}
}

int	main(int argc, char *argv[])
{
	argc++;
	ft_putstr(argv[0]);
	ft_putstr("\n");
	return (0);
}
