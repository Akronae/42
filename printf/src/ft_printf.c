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
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include "ft_boolean.h"
#include "ft_link.h"

t_link *ft_get_first_element(t_link *list)
{
	while (list->prev)
	{
		list = list->prev;
	}
	return list;
}

void ft_list_push(t_link **list)
{
	t_link *new_elem = malloc(sizeof(t_link));
	new_elem->prev = NULL;
	new_elem->next = NULL;
	new_elem->data = NULL;
	if (!*list)
	{
		*list = new_elem;
		return;
	}
	(*list)->next = new_elem;
	new_elem->prev = *list;
	*list = new_elem;

}

void ft_free_list(t_link *list)
{
	t_link *temp;
	list = ft_get_first_element(list);
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->data);
		free(temp);
	}
}

size_t ft_list_len(t_link *list)
{
	list = ft_get_first_element(list);
	size_t len;

	len = 0;
	while (TRUE)
	{
		len++;
		if (!list->next)
			break;
		list = list->next;
	}
	return (len);
}

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

char *ulonglong_to_str(unsigned long long nb)
{
	t_link *list = NULL;
	while (nb)
	{
		ft_list_push(&list);
		list->data = malloc(sizeof(int));
		*((char *) (list->data)) = nb % 10 + '0';
		nb /= 10;
	}
	char *str = malloc(sizeof(char) * (ft_list_len(list) + 1));
	size_t i = 0;
	while (TRUE)
	{
		str[i] = *((char *) list->data);
		i++;
		if (!list->prev)
			break;
		list = list->prev;
	}
	str[i] = '\0';
	ft_free_list(list);
	return str;
}

char *ft_arg_to_str(va_list args, enum t_type type)
{
	char *str;

	str = NULL;
	if (type == CHAR)
		str = ft_char_to_str(va_arg(args, int));
	if (type == INT)
		str = ft_itoa(va_arg(args, int));
	if (type == STRING)
		str = ft_strdup(va_arg(args, char *));
	if (type == POINTER)
		str = ulonglong_to_str(va_arg(args, unsigned long long));
	return (str);
}

char *char_to_str (char c)
{
	char *str = malloc(2);
	str[0] = c;
	str[1] = '\0';
	return str;
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int i = -1;
	t_link *a;

	va_start(args, input);
	while (input[++i])
	{
		ft_list_push(&a);

		if (input[i] == '%')
		{
			int type = ft_type_from_char(input[i + 1]);
			char *str = ft_arg_to_str(args, type);
			a->data = str;
			i += 1;
		}
		else
			a->data = char_to_str(input[i]);
	}
	va_end(args);

	a = ft_get_first_element(a);
	while (TRUE)
	{
		ft_putstr_fd(a->data, 0);
		if (!a->next) break;
		a = a->next;
	}
	ft_free_list(a);

	return (0);
}