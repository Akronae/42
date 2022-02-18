//
// Created by Alexandre DAUBRICOURT on 7/2/21.
//

int	is_char_alpha(char c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

int	is_char_num(char c)
{
	return (c >= 48 && c <= 57);
}

int	is_char_lower(char c)
{
	return (c >= 97 && c <= 122);
}

int	is_char_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (i == 0 || (!is_char_alpha(str[i - 1]) && !is_char_num(str[i - 1])))
		{
			if (is_char_lower(str[i]))
				str[i] = str[i] - 32;
		}
		else if (is_char_upper(str[i]))
			str[i] = str[i] + 32;
	}
	return (str);
}
