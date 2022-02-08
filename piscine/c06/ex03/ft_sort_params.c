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
	while (str[++i])
	{
		ft_putchar(str[i]);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				break ;
		}
		else
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	**sort_str_array(char **arr, int size)
{
	int		i;
	char	*a;
	char	*b;

	i = -1;
	while (++i < size - 1)
	{
		a = arr[i];
		b = arr[i + 1];
		if (ft_strcmp(a, b) > 0)
		{
			arr[i] = b;
			arr[i + 1] = a;
			i = -1;
		}
	}
	return (arr);
}

int	main(int argc, char *argv[])
{
	int	i;

	argv = sort_str_array(argv + 1, argc - 1);
	i = -1;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
	return (0);
}
