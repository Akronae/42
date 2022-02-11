/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/04 15:13:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_type.h"
#include "../libft/libft.h"

enum t_type ft_type_from_char(const char c)
{
	if (c == 'c')
		return (CHAR);
	if (c == 's')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	if (c == 'd')
		return (DECIMAL);
	if (c == 'i')
		return (INT);
	if (c == 'u')
		return (U_DECIMAL);
	if (c == 'x')
		return (HEXADECIMAL);
	return (-1);
}

char *ft_char_to_str(char c)
{
	char *str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void *arg_to_ptr (va_list args, enum t_type type)
{
	int *ptr;

	ptr = NULL;
	if (type == CHAR || type == DECIMAL || type == U_DECIMAL)
	{
		ptr = ft_calloc(1, sizeof(int));
		*ptr = va_arg(args, int);
	}
	return (ptr);
}

char *ft_arg_to_str(va_list args, enum t_type type)
{
	int *ptr = arg_to_ptr(args, type);
	char *str;

	str = NULL;
	if (type == CHAR)
		str = ft_char_to_str((char) *ptr);
	free(ptr);
	return (str);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int i = -1;
	char **arr = ft_calloc(ft_strlen(input), sizeof(int*));
	int arr_i = -1;

	va_start(args, input);
	while (input[++i])
	{
		if (input[i] == '%')
		{
			int type = ft_type_from_char(input[i + 1]);
			char *str = ft_arg_to_str(args, type);
			arr[++arr_i] = str;
			i += 1;
		}
		else
			arr[++arr_i] = input[i];
	}
	va_end(args);

	int a = -1;
	while (arr[++a])
	{
		ft_putstr_fd(arr[a], 0);
		free(arr[a]);
	}
	free(arr);

	return (0);
}