//
// Created by Alexandre DAUBRICOURT on 7/2/21.
//

int	is_char_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!is_char_upper(str[i]))
		{
			return (0);
		}
	}
	return (1);
}
