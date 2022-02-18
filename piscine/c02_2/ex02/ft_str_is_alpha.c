//
// Created by Alexandre DAUBRICOURT on 7/2/21.
//

int	is_char_alpha(char c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!is_char_alpha(str[i]))
		{
			return (0);
		}
	}
	return (1);
}
