//
// Created by Alexandre DAUBRICOURT on 7/2/21.
//

int	is_char_num(char c)
{
	return (c >= 48 && c <= 59);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!is_char_num(str[i]))
		{
			return (0);
		}
	}
	return (1);
}
