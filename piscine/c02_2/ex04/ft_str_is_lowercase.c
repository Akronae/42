//
// Created by Alexandre DAUBRICOURT on 7/2/21.
//

int	is_char_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!is_char_lower(str[i]))
		{
			return (0);
		}
	}
	return (1);
}
